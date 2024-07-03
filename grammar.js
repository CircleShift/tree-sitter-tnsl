
module.exports = grammar({
  name: "tnsl",

  inline: $ => [
    $._literal,

    $._top_stmt, $._method_stmt,
    $._function_stmt, $._control_stmt,
  ],

  extras: $ => [
    $.doc_comment,
    $.comment,
    /[\s]/,
  ],

  conflicts: $ => [
    [$.if, $.if],
  ],

  rules: {

    //
    // Top level
    //

    top_level: $ => repeat($._top_stmt),

    _top_stmt: $ => choice(
      alias($._top_block, $.block),
      seq($.import, $.newline),
      seq($.asm, $.newline),
      seq($.declaration, $.newline),
    ),

    _top_block: $ => seq(
      field("open", "/;"),
      choice($.module, $.method, $.function),

      repeat(seq(
        field("reopen", ";;"),
        choice($.module, $.method, $.function)
      )),

      field("close", ";/"),
    ),

    //
    // Module
    //

    module: $ => seq(
      optional("export"),
      "module",
      $.identifier,

      optional(seq(
        $.newline,
        repeat($._top_stmt),
      )),
    ),

    //
    // Method
    //

    method: $ => seq(
      "method",
      choice($.builtin_type, alias($.identifier, $.user_type)),
      optional(seq(
        "impl",
        alias($.identifier, $.user_type),
        repeat(seq(",", alias($.identifier, $.user_type))),
      )),

      optional(seq(
        $.newline,
        repeat($._method_stmt),
      )),
    ),

    _method_stmt: $ => choice(
      alias($._method_block, $.block),
    ),

    _method_block: $ => seq(
      field("open", "/;"),
      choice($.function),

      repeat(seq(
        field("reopen", ";;"),
        choice($.function)
      )),

      field("close", ";/"),
    ),

    //
    // Functions
    //

    function: $ => seq(
      field("name", $.identifier),
      optional($.param_list),
      optional($.output_list),

      optional(seq(
        $.newline,
        repeat($._function_stmt),
      )),
    ),

    _function_stmt: $ => choice(
      alias($._function_block, $.block),
      seq($.asm, $.newline),
      seq($.return, $.newline),
      seq($.declaration, $.newline),
    ),

    _function_block: $ => seq(
      field("open", "/;"),
      choice($.if, $.loop),

      repeat(seq(
        field("reopen", ";;"),
        choice($.if, $.loop)
      )),

      field("close", ";/"),
    ),

    //
    // Control flow blocks
    //

    if: $ => prec.dynamic(0, seq(
      "if",
      "(", $.expr_list, ")",
      optional(seq("[", $.expr_list, "]")),

      optional(seq(
        $.newline,
        repeat($._control_stmt),
      )),

      optional(repeat($.else_if)),
      optional($.else),
    )),

    else_if: $ => seq(
      choice(seq(";/", "/;"), ";;"),
      "else", "if",
      "(", $.expr_list, ")",

      optional(seq(
        $.newline,
        repeat($._control_stmt),
      )),
    ),

    else: $ => seq(
      choice(seq(";/", "/;"), ";;"),
      "else",

      optional(seq(
        $.newline,
        repeat($._control_stmt),
      )),
    ),

    loop: $ => seq(
      "loop",
      optional(seq("(", $.expr_list, ")")),
      optional(seq("[", $.expr_list, "]")),

      optional(seq(
        $.newline,
        repeat($._control_stmt),
      )),
    ),

    _control_stmt: $ => choice(
      seq($.control, $.newline),
      $._function_stmt,
    ),

    //
    // Declarations and expressions
    //

    declaration: $ => seq(
      $.type,
      $.identifier,
      optional("="),

      repeat(seq(
        ",",
        $.identifier,
        optional("=")
      )),
    ),

    expr: $ => choice(
      // TODO
      "a"
    ),

    //
    // Special statements
    //

    asm: $ => seq("asm", $.string_literal),

    import: $ => seq(optional(":"), "import", choice($.import_literal, $.string_literal)),

    control: $ => seq(choice("continue", "break"), optional($.integer)),

    return: $ => seq("return", optional($.expr)),

    identifier: _ => /[^`!-@\[-^{-~\s][^!-@\[-^{-~`\s]*/,

    type: $ => seq(
      repeat(choice(
        "~", seq("{", alias($.integer, $.numeric_literal), "}")
      )),

      choice(
        seq(
          alias("void", $.builtin_type),
          optional(seq("(", optional($.type_list), ")")),
          optional(seq("[", optional($.type_list), "]")),
        ),
        seq(
          choice($.builtin_type, alias($.identifier, $.user_type)),
          optional(seq("(", $.type_list, ")")),
          optional("`"),
        ),
      ),
    ),

    //
    // Lists
    //

    type_list: $ => seq(
      $.type, repeat(seq(",", $.type)),
    ),

    param_list: $ => seq(
      "(",
      optional(seq(
        $.type, $.identifier,
        repeat(seq(",", optional($.type), $.identifier)),
      )),
      ")",
    ),

    output_list: $ => seq(
      "[",
      optional(seq(
        $.type, repeat(seq(",", $.type)),
      )),
      "]",
    ),

    expr_list: $ => seq(
      $.expr, repeat(seq(";", optional($.expr))),
    ),

    //
    // Misc
    //

    builtin_type: _ => choice(
      "int", "int8", "int16", "int32", "int64",
      "uint", "uint8", "uint16", "uint32", "uint64",
      "float", "float32", "float64",
      "bool", "vect", "type"
    ),

    newline: _ => choice('\0', /[\r\n]+/),

    integer: _ => /[0-9]+/,

    string_literal: _ => seq("\"", /([^\"\\]|\\[^u]|\\u[0-9A-Fa-f])*/, "\""),

    import_literal: _ => seq("\'", /([^\"\\]|\\[^u]|\\u[0-9A-Fa-f])*/, "\'"),

    char_literal: _ => seq("\'", /([^\"\\]|\\[^u]|\\u[0-9A-Fa-f])/, "\'"),

    numeric_literal: _ => choice(
      // Binary
      /0[Bb][01]+/,
      // Octal
      /0[Oo][0-7]+(\.[0-7]+)?/,
      // Hex
      /0[Xx][0-9a-fA-F]+(\.[0-9a-fA-F]+)?/,
      // Decimal
      /[0-9]+(\.[0-9]+)?/,
    ),

    _literal: $ => choice(
      $.string_literal,
      $.char_literal,
      $.numeric_literal,
    ),

    doc_comment: _ => token(choice(
      seq("##", /.*/),
      seq(
        "/##", /([^#]|#([\r\n]+|[^\/][^\r\n]*))*/, "#/"
      ),
    )),

    comment: _ => token(choice(
      seq("#", /.*/),
      seq(
        "/#", /([^#]|#([\r\n]+|[^\/][^\r\n]*))*/, "#/"
      ),
    )),

  }

});
