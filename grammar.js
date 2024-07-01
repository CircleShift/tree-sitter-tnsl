
module.exports = grammar({
  name: "tnsl",

  inline: $ => [
    $.top_level_block,
    $.method_block,
    $.func_block,

    $.func_stmt,
    $.func_block_stmt,
    $.id_val,
  ],

  extras: $ => [
    /[\s]/
  ],

  conflicts: $ => [
    [$.type, $.expr],
  ],

  rules: {

    top_level: $ => repeat(choice(
      $.top_level_block,
      $.declaration,
      $.asm,
      $.import,
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
        $.import,
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

      choice(
        $.if,
        $.loop,
      ),

      repeat(seq(
        ";;",
        choice(
          $.if,
          $.loop,
        ),
      )),
      ";/",
    ),

    if: $ => prec.left(seq(
      "if",
      seq("(", $.expr_list, ")"),
      optional(seq("[", $.type_list, "]")),

      optional(seq(
        $.newline,
        repeat($.func_block_stmt),
      )),

      repeat(seq(
        choice(";;", seq(";/", optional($.newline), "/;")),
        $.else_if,
      )),

      optional(seq(
        choice(";;", seq(";/", optional($.newline), "/;")),
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

    import: $ => seq(
      optional(":"),
      "import",
      choice($.import_literal, $.string_literal),
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

    import_literal: $ => seq("\'", /([^\'\\]|\\[^u]|\\u[0-9a-fA-F]+)*/, "\'"),
    string_literal: $ => seq("\"", /([^\"\\]|\\[^u]|\\u[0-9a-fA-F]+)*/, "\""),
    integer: $ => /[0-9]+/,

    inbuilt_type: $ => choice(
      /u?int(8|16|32|64)?/,
      /float(32|64)?/,
      "type",
      "vect",
      "bool"
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
          choice(
            $.inbuilt_type,
            seq(
              repeat(seq($.identifier, ".")),
              alias($.identifier, $.user_type),
            ),
          ),
          optional(seq("(", $.type_list, ")")),
        ),
      ),
    ),

    identifier: $ => /[^`!-@\[-^{-~\s][^!-/:-@\[-^{-~`\s]*/,

    //
    // TODO: EXPRESSION
    //

    numeric_literal: $ => choice(
      /0[Bb][01]+(\.[01]+)?/,
      /0[Oo][0-7]+(\.[0-7]+)?/,
      /0[Xx][0-9a-fA-F]+(\.[0-9a-fA-F]+)?/,
      /[0-9]+(\.[0-9]+)?/,
    ),

    char_literal: $ => seq("'", /([^\'\\]|\\[^u]|\\u[0-9a-fA-F])/, "'"),

    bool_literal: $ => choice("true", "false"),

    id_val: $ => prec.right(seq(
      $.identifier,
      repeat(choice(
        "`",
        seq("{", $.expr, "}"),
        seq("(", $.expr_list, ")"),
      )),
    )),

    expr: $ => choice(
      seq("(", $.expr, ")"),
      seq("{", $.expr_list, "}"),

      prec.left(1, seq($.expr, /([&|^+\-*/%])?=/, $.expr)),
      prec.right(2, seq($.expr, /!?(&&|\|\||\^\^)/, $.expr)),
      prec.left(3, seq($.expr, /((!|<|>)?==|!?(<|>))/, $.expr)),
      prec.left(5, seq($.expr, /[+\-]/, $.expr)),
      prec.left(6, seq($.expr, /[*/%]/, $.expr)),
      prec(7, seq("len", $.expr)),
      prec(8, seq(choice("--", "++"), $.expr)),
      prec(9, seq("~", $.expr)),
      prec.right(10, seq($.expr, ".", $.id_val)),

      $.string_literal,
      $.char_literal,
      $.numeric_literal,
      $.bool_literal,

      $.id_val,
    ),



  }

});
