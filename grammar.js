module.exports = grammar({
  name: "TNSL",

  inline: $ => [
    $.top_block_inner,
    $.function_block_inner,
  ],

  rules: {

    //
    // Top level rules
    //

    top_level: $ => repeat(choice(
      // $.top_level_statement,
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

    //
    // Function rules
    //

    function_inner: $ => seq(
      $.identifier,
      optional(seq("(", optional($.param_list), ")")),
      optional(seq("[", optional($.type_list), "]")),
      repeat(choice(
        //$.function_statement,
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
        "if",
        seq("else", optional("if"))
      ),
      repeat(choice(
        // $.function_block_statement,
        $.function_block
      ))
    ),

    loop_block: $ => seq(
      "loop",
      //optional(seq("(", $.statement_list, ")"))
      //optional(seq("[", $.statement_list, "]"))
      repeat(choice(
        // $.function_block_statement,
        $.function_block
      ))
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

    full_type: $ => seq(
      repeat(choice(
        "~",
        /\{[0-9]*\}/
      )),
      $.identifier,
      optional(seq("(", $.type_list, ")")),
      optional("`")
    ),

    param_list: $ => repeat1(seq(
      $.full_type,
      $.identifier,
      repeat(seq(",", $.identifier)),
    )),

    //
    // Misc
    //

    identifier: $ => /[^!-@\[-^{-~`\s][^!-/:-@\[-^{-~`\s]*/,

    binary_number: $ => /0[Bb][01]+(\.[01]+)?/,
    octal_number: $ => /0[Oo][0-7]+(\.[0-7]+)?/,
    hex_number: $ => /0[Xx][0-9a-fA-F]+(\.[0-9a-fA-F]+)?/,
    decimal_number: $ => /[0-9]+(\.[0-9]+)?/,
  }

});
