module.exports = grammar({
  name: "TNSL",

  inline: $ => [
    $.top_block_inner,
    $.function_block_inner,
    $.function_statement,
    $.function_block_statement,
  ],

  conflicts: $ => [
  ],

  rules: {

    //
    // Top level rules
    //

    top_level: $ => repeat(choice(
      $.top_level_statement,
      $.top_level_block
    )),

    top_level_block: $ => seq(
    "/;",
    $.top_block_inner,
    repeat(seq(
      ";;",
      $.top_block_inner
    )),
    ";/"
    ),

    top_block_inner: $ => choice(
      $.function_inner,
      // $.method_inner,
      $.module_inner
    ),

    top_level_statement: $ => choice(
      $.definition,
      $.asm_expr,
    ),

    //
    // Function rules
    //

    function_inner: $ => seq(
      $.identifier,
      optional(seq("(", optional($.param_list), ")")),
      optional(seq("[", optional($.type_list), "]")),
      repeat(choice(
        $.function_statement,
        $.function_block
      ))
    ),

    function_block: $ => seq(
      "/;",
      $.function_block_inner,
      repeat(seq(
        ";;",
        $.function_block_inner
      )),
      ";/"
    ),

    function_block_inner: $ => choice(
      $.if_block,
      $.loop_block,
      //$.match_block,
      //$.anonymous_function,
    ),

    if_block: $ => seq(
      choice(
        "else",
        seq(
          optional("else"),
          "if",
          optional(seq("(", optional($.statement_list), ")")),
        )
      ),
      repeat(choice(
        $.function_block_statement,
        $.function_block
      ))
    ),

    loop_block: $ => seq(
      "loop",
      optional(seq("(", optional($.statement_list), ")")),
      optional(seq("[", optional($.statement_list), "]")),
      repeat(choice(
        $.function_block_statement,
        $.function_block
      ))
    ),

    function_statement: $ => choice(
      $.definition,
      $.expr,
      seq("return", $.expr)
    ),

    function_block_statement: $ => choice(
      $.function_statement,
      $.control_expr,
    ),

    //
    // Module rules
    //

    module_inner: $ => seq(
      optional("export"),
      "module",
      $.identifier,
      repeat(choice(
        // $.top_level_statement,
        $.top_level_block
      ))
    ),

    //
    // Types and lists
    //

    type_list: $ => seq(
        $.full_type,
        repeat(seq(",", $.full_type))
    ),

    full_type: $ => prec(3, seq(
      repeat(choice(
        "~",
        "{}",
        seq("{", $.integer, "}")
      )),
      $.identifier,
      optional(seq("(", $.type_list, ")")),
      optional("`")
    )),

    param_list: $ => repeat1(seq(
      $.full_type,
      $.identifier,
      repeat(seq(",", $.identifier)),
    )),

    statement_list: $ => prec(1, seq(
      choice($.definition, $.expr),
      repeat(seq(
        ";",
        choice($.definition, $.expr),
      ))
    )),

    expr_list: $ => seq(
      $.expr,
      repeat(seq(
        ",",
        $.expr
      ))
    ),

    //
    // Misc
    //

    definition: $ => seq(
      $.full_type,
      $.identifier,
      optional(seq(
        "=",
        $.expr
      )),

      repeat(seq(
        ",",
        $.identifier,
        optional(seq(
          "=",
          $.expr
        ))
      ))
    ),

    binary_expr: $ => prec.right(choice(
      // Assignment expansion
      prec(3, seq($.expr, /[&|^+\-*/%]=/, $.expr)),

      // Boolean logic
      prec(7, seq($.expr, /!?(&&|\|\||\^\^)/, $.expr)),
      prec(6, seq($.expr, /(!|<|>)?==/, $.expr)),

      // Bitwise
      prec(8, seq($.expr, /!?(&|\||\^)/, $.expr)),
      prec(8, seq($.expr, /(<<|>>)/, $.expr)),

      // Comparison
      prec(6, seq($.expr, /!?(<|>)/, $.expr)),

      // Single character binary ops
      prec(3, seq($.expr, "=", $.expr)),
      prec(4, seq($.expr, /[+\-]/, $.expr)),
      prec(5, seq($.expr, /[*/%]/, $.expr)),
    )),

    post_expr: $ => prec(1, choice(
      seq($.expr, "++"),
      seq($.expr, "--"),
    )),

    pre_expr: $ => prec(2, choice(
      seq("++", $.expr),
      seq("--", $.expr),
      seq("!", $.expr),
      seq("~", $.expr),
      seq("-", $.expr),
    )),

    asm_expr: $ => seq(
      "asm", $.string_literal
    ),

    expr: $ => choice(
      seq("(", $.expr, ")"),
      $.literal,
      $.identifier_expr,
      $.asm_expr,
      $.post_expr,
      $.binary_expr,
      $.pre_expr,
    ),

    control_expr: $ => seq(
      /(break|continue)/,
      optional($.integer)
    ),

    identifier: $ => /[^!-@\[-^{-~`\s][^!-/:-@\[-^{-~`\s]*/,

    identifier_expr: $ => prec.right(seq(
      $.identifier,
      optional(seq("(", $.expr_list, ")")),
      repeat(choice(
        seq("{", $.expr, "}"),
        "`"
      )),

      repeat(prec.right(seq(
        ".",
        $.identifier,
        optional(seq("(", $.expr_list, ")")),
        repeat(choice(
          seq("{", $.expr, "}"),
          "`"
        )),
      ))),
    )),

    integer: $ => /[0-9]+/,

    numeric_literal: $ => choice(
      // Binary
      /0[Bb][01]+(\.[01]+)?/,
      // Octal
      /0[Oo][0-7]+(\.[0-7]+)?/,
      // Hex
      /0[Xx][0-9a-fA-F]+(\.[0-9a-fA-F]+)?/,
      // Decimal
      /[0-9]+(\.[0-9]+)?/,
    ),

    character_literal: $ => /\'([^\\]|\\[^u]|\\u[0-9a-fA-F]+)\'/,

    string_literal: $ => token(seq(
      "\"",
      repeat(/([^"\\]|\\[^u]|\\u[0-9a-fA-F]+)/),
      "\""
    )),

    bool_literal: $ => choice("true", "false"),

    literal: $ => choice(
      $.bool_literal,
      $.numeric_literal,
      $.character_literal,
      $.string_literal,
    )
  }

});
