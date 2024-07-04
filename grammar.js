module.exports = grammar({
  name: "tnsl",

  inline: $ => [
    $._literal,

    $._top_stmt, $._method_stmt,
    $._function_stmt, $._control_stmt,
    $._list_stmt,
  ],

  extras: $ => [
    $.doc_comment,
    $.comment,
    /[\s]/,
  ],

  conflicts: $ => [
    [$.if, $.if],
    [$.pointer_val, $.type],
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
      $.struct,
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
      seq($.expr, $.newline),
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
      $.stmt_list,
      optional($.output_list),

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
      $.stmt_list,

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
      optional($.stmt_list),
      optional($.repeat_list),

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
      optional(seq("=", $.expr)),

      repeat(seq(
        ",",
        $.identifier,
        optional(seq("=", $.expr)),
      )),
    ),

    expr: $ => choice(
      // TODO
      prec.left(1, seq($.expr, /[&|^+\-*\/%]?=/, $.expr)),
      prec.left(2, seq($.expr, /!?(\&\&|\|\||\^\^)/, $.expr)),
      prec.left(3, seq($.expr, /((!|<|>)?==|!?(<|>))/, $.expr)),
      prec.left(4, seq($.expr, /(!|!?[&|^]|<<|>>)/, $.expr)),
      prec.left(5, seq($.expr, choice("+", "-"), $.expr)),
      prec.left(6, seq($.expr, choice("*", "/", "%"), $.expr)),
      prec(7, seq("len", $.expr)),
      prec(8, seq(choice("--", "++"), $.expr)),
      prec(9, seq($.expr, choice("--", "++"))),

      $.pointer_val,
      seq($.expr, ".", $.ident_val),

      $._literal,
      $.compound_expr,
      seq("(", $.expr, ")"),
    ),

    //
    // Special statements
    //

    asm: $ => seq("asm", $.string_literal),

    import: $ => seq(optional(":"), "import", choice($.import_literal, $.string_literal)),

    control: $ => seq(choice("continue", "break"), optional(alias($.integer, $.numeric_literal))),

    return: $ => seq("return", optional($.expr)),

    identifier: _ => /[^`!-@\[-^{-~\s][^!-@\[-^{-~`\s]*/,

    pointer_val: $ => prec.right(seq(
      optional("~"),
      $.identifier,
      repeat(choice(
        "`",
        $.call_expr,
        $.index_expr,
      )),

      repeat(seq(
        ".",
        $.identifier,
        repeat(choice(
          "`",
          $.call_expr,
          $.index_expr,
        )),
      )),
    )),

    ident_val: $ => prec.right(seq(
      $.identifier,
      repeat(choice(
        "`",
        $.call_expr,
        $.index_expr,
      )),

      repeat(seq(
        ".",
        $.identifier,
        repeat(choice(
          "`",
          $.call_expr,
          $.index_expr,
        )),
      )),
    )),

    call_expr: $ => seq("(", optional(seq($.expr, repeat(seq(",", $.expr)))), ")"),

    index_expr: $ => seq("{", $.expr, "}"),

    compound_expr: $ => seq("{", $.expr, repeat(seq(",", $.expr)), "}"),

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
          choice(
            $.builtin_type,
            seq(
              repeat(seq($.identifier, ".")),
              alias($.identifier, $.user_type)
            )
          ),
          optional(seq("(", $.type_list, ")")),
          optional("`"),
        ),
      ),
    ),

    struct: $ => seq(
      "struct",
      field("name", $.identifier),
      optional($.param_list),
      $.data_list,
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

    data_list: $ => seq(
      "{",
      optional(seq(
        $.type, $.identifier,
        repeat(seq(",", optional($.type), $.identifier)),
      )),
      "}",
    ),

    output_list: $ => seq(
      "[",
      optional(seq(
        $.type, repeat(seq(",", $.type)),
      )),
      "]",
    ),

    stmt_list: $ => seq(
      "(",
      $._list_stmt, repeat(seq(";", optional($._list_stmt))),
      ")",
    ),

    repeat_list: $ => seq(
      "[",
      $._list_stmt, repeat(seq(";", optional($._list_stmt))),
      "]",
    ),

    _list_stmt: $ => choice(
      $.declaration,
      $.expr,
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

    escape: _ => token.immediate(prec(1, /(\\[^u]|\\u[0-9a-fA-F])/)),

    string_literal: $ => seq(
      "\"",
      repeat(choice(
        token.immediate(prec(1, /[^\"\\]+/)),
        $.escape,
      )),
      "\""
    ),

    import_literal: $ => seq(
      "\'",
      repeat(choice(
        token.immediate(prec(1, /[^\'\\]+/)),
        $.escape,
      )),
      "\'"
    ),

    char_literal: $ => seq(
      "\'",
      choice(
        token.immediate(prec(1, /[^\'\\]/)),
        $.escape,
      ),
      "\'"
    ),

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

    bool_literal: _ => choice("true", "false"),

    _literal: $ => choice(
      $.string_literal,
      $.char_literal,
      $.numeric_literal,
      $.bool_literal,
      alias("null", $.null),
      alias("self", $.self),
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
