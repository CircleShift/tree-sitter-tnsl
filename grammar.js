
module.exports = grammar({
  name: "TNSL",

  inline: $ => [
    $.top_level_block,
    $.method_block,
    $.func_block,

    $.func_stmt,
    $.func_block_stmt,
  ],

  extras: $ => [
    /[\s]/
  ],

  conflicts: $ => [
  ],

  rules: {

    top_level: $ => repeat(choice(
      $.top_level_block,
      $.declaration,
      $.asm,
      $.include,
      $.struct,
      $.newline,
    )),

    newline: $ => choice('\0', /[\r\n]+/),

    top_level_block: $ => seq(
      "/;",
      choice($.module, $.method, $.func),
      repeat(seq(
        ";;",
        choice($.module, $.method, $.func),
      )),
      ";/",
    ),

    module: $ => seq(
      // First line
      optional("export"),
      "module",
      $.identifier,
      $.newline,

      repeat(choice(
        $.top_level_block,
        $.declaration,
        $.asm,
        $.include,
        $.struct,
        $.newline,
      )),
    ),

    method: $ => seq(
      // First line
      "method", alias($.identifier, $.user_type),
      optional(seq("impl", $.identifier)),

      optional(seq(
        $.newline,
        repeat($.method_block),
      )),
    ),

    method_block: $ => seq(
      "/;",
      choice($.func, $.operator),
      repeat(seq(
        ";;",
        choice($.func, $.operator),
      )),
      ";/",
    ),

    struct: $ => seq(
      "struct",
      alias($.identifier, $.user_type),
      optional(seq("(", $.type_list, ")")),
      "{", $.param_list, "}",
    ),

    func: $ => seq(
      // Declaration
      $.identifier,
      optional(seq("(", $.param_list, ")")),
      optional(seq("[", $.type_list, "]")),

      optional(seq(
        $.newline,
        repeat($.func_stmt),
      )),
    ),

    operator: $ => seq(
      "operator",
      optional(seq("(", $.type, $.identifier, ")")),
      "[", $.type, "]",

      optional(seq(
        $.newline,
        repeat($.func_stmt),
      )),
    ),

    func_stmt: $ => choice(
      $.func_block,
      $.declaration,
      $.asm,
      $.return,
      $.expr,
      $.newline,
    ),

    func_block_stmt: $ => choice(
      $.control,
      $.func_stmt,
    ),

    func_block: $ => seq(
      "/;",
      choice($.if, $.loop),
      repeat(seq(
        ";;",
        choice($.if, $.loop),
      )),
      ";/",
    ),

    if: $ => prec.right(seq(
      "if",
      seq("(", $.expr_list, ")"),
      optional(seq("[", $.type_list, "]")),

      optional(seq(
        $.newline,
        repeat($.func_block_stmt),
      )),

      repeat(seq(
        choice(
          ";;",
          seq(";/", optional($.newline), "/;"),
        ),
        $.else_if,
      )),

      optional(seq(
        choice(
          ";;",
          seq(";/", optional($.newline), "/;"),
        ),
        $.else,
      )),
    )),

    else_if: $ => seq(
      "else", "if",
      seq("(", $.expr_list, ")"),

      optional(seq(
        $.newline,
        repeat($.func_block_stmt),
      )),
    ),

    else: $ => seq(
      "else",

      optional(seq(
        $.newline,
        repeat($.func_block_stmt),
      )),
    ),

    loop: $ => seq(
      "loop",
      optional(seq("(", $.expr_list, ")")),
      optional(seq("[", $.expr_list, "]")),

      optional(seq(
        $.newline,
        repeat($.func_block_stmt),
      )),
    ),

    expr_list: $ => seq(
      $.expr,
      repeat(seq(";", optional($.newline), $.expr)),
    ),

    param_list: $ => seq(
      $.type,
      $.identifier,
      repeat(seq(",", optional($.newline), optional($.type), $.identifier)),
    ),

    type_list: $ => seq(
      $.type,
      repeat(seq(",", optional($.newline), $.type)),
    ),

    control: $ => seq(
      /(continue|break)/,
      optional($.integer),
      $.newline,
    ),

    return: $ => seq(
      "return",
      optional($.expr),
      $.newline,
    ),

    include: $ => seq(
      optional(":"),
      "include",
      choice($.include_literal, $.string_literal),
      $.newline,
    ),

    asm: $ => seq(
      "asm",
      $.string_literal,
      $.newline,
    ),

    declaration: $ => seq(
      $.type, $.identifier,
      optional(seq("=", optional($.newline), $.expr)),

      repeat(seq(
        ",", optional($.newline),
        $.identifier,
        optional(seq("=", optional($.newline), $.expr)),
      )),

      $.newline,
    ),

    include_literal: $ => seq("\'", /([^\'\\]|\\[^u]|\\u[0-9a-fA-F]+)*/, "\'"),
    string_literal: $ => seq("\"", /([^\"\\]|\\[^u]|\\u[0-9a-fA-F]+)*/, "\""),
    integer: $ => /[0-9]+/,

    inbuilt_type: $ => choice(
      /u?int(8|16|32|64)?/,
      /float(32|64)?/,
      "type",
      "vect",
    ),

    type: $ => seq(
      repeat(choice(
        "~",
        seq("{", $.integer, "}")
      )),

      choice(
        seq(
          "void",
          optional(seq("(", $.type_list, ")")),
          optional(seq("[", $.type_list, "]")),
        ),
        seq(
          choice($.inbuilt_type, alias($.identifier, $.user_type)),
          optional(seq("(", $.type_list, ")")),
        ),
      ),
    ),

    identifier: $ => /[^`!-@\[-^{-~\s][^!-/:-@\[-^{-~`\s]*/,

    //
    // TODO: EXPRESSION
    //

    expr: $ => /a/,



  }

});
