/**
 * @file TNSL Language Parser
 * @author Kai Gunger <kgunger@gmail.com>
 * @license MIT
 */

/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

// Whitespace and newlines
const NL = new RustRegex("[\\r\\n]");
const NL_ = seq(NL, repeat(NL));
const _NL = repeat(NL);
const WS = new RustRegex("[\\s&&[^\\r\\n]]");
const BLOCK_SEP = choice(";;", seq( ";/", _NL, "/;" ));

// Used when defining identifiers
const ANTI_RESERVED = '[^`~!@#$%^&*()\\-=+\\[\\]{}\\\\|;:\'",<.>/?]';

module.exports = grammar({
  name: "tnsl",

  extras: $ => [WS, $.comment],

  conflicts: $ => [
    [$.type_prefix, $.pre_op],
    [$.value, $._identifier_qualified],
    [$._type_prefix_array, $.value_list],
    [$.if_block, $.if_block],
  ],

  rules: {
    // TODO: add the actual grammar rules

    // ====================
    // Top level constructs
    // ====================

    source: $ => repeat($._mod_stmt),

    _mod_stmt: $ => choice(
      NL,

      $.struct,
      $.enum,
      $.import_file,
      $.asm,
      $.definition,

      $.mod_block,
    ),

    mod_head: $ => seq(
      optional("export"),
      "module",
      field("name", $.identifier),
    ),

    mod_body: $ => seq(
      NL, repeat($._mod_stmt),
    ),

    mod: $ => seq(
      $.mod_head, optional($.mod_body),
    ),

    mod_block: $ => seq(
      "/;", $._mod_block_inner,
      repeat(seq(
        ";;", $._mod_block_inner,
      )),
      ";/",
    ),

    _mod_block_inner: $ => choice(
      // Function definition
      $.func,
      // Sub-module
      $.mod,
      // Method definition
      $.method,
    ),

    // =================
    // Method definition
    // =================

    _method_stmt: $ => choice(
      NL,

      $.method_block,
    ),

    method_head: $ => seq(
      "method", alias($._identifier_qualified, $.type),
    ),

    method_body: $ => seq(
      NL, repeat($._method_stmt),
    ),

    method: $ => seq(
      $.method_head, optional($.method_body),
    ),

    method_block: $ => seq(
      "/;", $._method_block_inner,
      repeat(seq(
        ";;", $._method_block_inner,
      )),
      ";/",
    ),

    _method_block_inner: $ => choice(
      $.func,
      $._operator_function
    ),

    _operator_function: $ => seq(
      "operator", _NL
    ),

    // =================
    // Struct definition
    // =================

    struct: $ => seq(
      "struct",
      field("name", $.identifier), _NL,
      optional(seq($.parameter_list, _NL)),
      $.struct_data_list
    ),

    struct_data_list: $ => seq(
      "{", _NL,
      optional(seq(
        $.type, _NL, $.identifier, _NL,
        repeat(seq(
          ",", _NL, optional(seq($.type, _NL)), $.identifier, _NL
        )),
      )),
      "}",
    ),

    // ===============
    // Enum definition
    // ===============

    enum: $ => seq(
      "enum",
      field("name", $.identifier), _NL,
      optional(seq($.type_list, _NL)),
      $.enum_list
    ),

    enum_list: $ => seq(
      "{", _NL,
      optional(seq(
        $.identifier, optional(seq(_NL, "=", _NL, $.value)), _NL,
        repeat(seq(
          ",", _NL, $.identifier, optional(seq(_NL, "=", _NL, $.value)), _NL,
        )),
      )),
      "}",
    ),

    // ===================
    // Function definition
    // ===================

    _func_stmt: $ => prec(1, choice(
      NL,

      seq($._stmt, NL),

      seq($.func_block, NL),
    )),

    func_head: $ => seq(
      field("name", $.identifier),
      optional($.parameter_list),
      optional($.type_list),
    ),

    func_body: $ => seq(
      NL, repeat($._func_stmt),
    ),

    func: $ => seq(
      $.func_head, optional($.func_body),
    ),

    func_block: $ => seq(
      "/;", $._func_block_inner,
      repeat(seq(
        ";;", $._func_block_inner,
      )),
      ";/",
    ),

    _func_block_inner: $ => choice(
      $.if_block,
      $.loop_block,
      $.func,
      // Not yet defined
      // $.match_block,
      // $.anonymous_function
    ),

    // Control Flow - IF

    if_head: $ => seq(
      "if", $.start_stmt_list,
    ),

    else_if_head: $ => seq(
      "else", $.if_head,
    ),

    else_head: $ => seq(
      "else",
    ),

    if_block: $ => seq(
      $.if_head, optional($.func_body),

      repeat(seq(
        BLOCK_SEP, $.else_if_head, optional($.func_body),
      )),

      optional(seq(
        BLOCK_SEP, $.else_head, optional($.func_body),
      ))
    ),

    // Control Flow - LOOP

    loop_head: $ => seq(
      "loop", optional($.start_stmt_list), optional($.end_stmt_list)
    ),

    loop_block: $ => seq(
      $.loop_head, optional($.func_body),
    ),

    // Control Flow - MATCH

    // TODO

    // Control Flow - Stmt lists

    start_stmt_list: $ => seq(
      "(", _NL,
      repeat(seq($._stmt, _NL, ";", _NL)),
      optional(seq($._stmt, _NL)),
      ")"
    ),

    end_stmt_list: $ => seq(
      "[", _NL,
      repeat(seq($._stmt, _NL, ";", _NL)),
      optional(seq($._stmt, _NL)),
      "]"
    ),

    // ===========
    // Definitions
    // ===========

    definition: $ => seq(
      $.type,

      $.identifier,
      optional(seq(
        "=", _NL, $.value,
      )),

      repeat(seq(
        ",", _NL, $.identifier,
        optional(seq(
          "=", _NL, $.value,
        ))
      ))
    ),

    // =====
    // Lists
    // =====

    parameter_list: $ => seq(
      "(", _NL,
      optional(seq(
        $.type, _NL, $.identifier, _NL,
        repeat(seq(
          ",", _NL, optional(seq($.type, _NL)), $.identifier, _NL,
        )),
      )),
      ")",
    ),

    type_list: $ => seq(
      "[", _NL,
      optional(seq(
        $.type, _NL,
        repeat(seq(
          ",", _NL, $.type, _NL
        )),
      )),
      "]",
    ),

    value_list: $ => seq(
      "{", _NL,
      optional(seq(
        $.value, _NL,
        repeat(seq(
          ",", _NL, $.value, _NL
        )),
      )),
      "}"
    ),

    call_list: $ => seq(
      "(", _NL,
      optional(seq(
        $.value, _NL,
        repeat(seq(
          ",", _NL, $.value, _NL
        )),
      )),
      ")"
    ),

    // =====
    // Types
    // =====

    _type_prefix_array: $ => seq(
      "{", _NL,
      optional(seq($.value, _NL)),
      "}"
    ),

    type_prefix: $ => choice(
      "~", $._type_prefix_array,
    ),

    type_postfix: _ => choice(
      "`",
    ),

    type: $ => prec.right(1, seq(
      repeat($.type_prefix),
      choice(
        seq(
          $._identifier_qualified,
          optional($.call_list)
        ),

        seq(
          field("name", alias("void", $.void)),
          optional($.call_list),
          optional($.type_list)
        ),

        seq(
          field("name", alias("yield", $.yield)),
          optional($.type_list)
        ),
      ),
      repeat($.type_postfix),
    )),

    // ======
    // Values
    // ======

    identifier: _ => new RustRegex(`[\\S&&${ANTI_RESERVED}&&[^0-9]][\\S&&${ANTI_RESERVED}]*`),

    _identifier_qualified: $ => prec.right(seq(
      repeat(seq($.identifier, ".", _NL)), field("name", $.identifier)
    )),

    string: _ => new RustRegex("(?m)\\\"([^\\\"\\\\]|\\\\[^u]|\\\\u[0-9a-fA-F]+)*\\\""),
    import_string: _ => new RustRegex("(?m)'([^'\\\\]|\\\\[^u]|\\\\u[0-9a-fA-F]+)*'"),
    character: _ => new RustRegex("(?m)'([^'\\\\]|\\\\[^u]|\\\\u[0-9a-fA-F]+)'"),

    _binary_literal: $ => new RustRegex("0b[01]+(\\.[01]+)?"),
    _octal_literal: $ => new RustRegex("0o[0-7]+(\\.[0-7]+)?"),
    _decimal_literal: $ => new RustRegex("[0-9]+(\\.[0-9]+)?"),
    _hex_literal: $ => new RustRegex("0x[0-9a-fA-F]+(\\.[0-9a-fA-F]+)?"),

    numeric_literal: $ => choice(
      $._binary_literal,
      $._octal_literal,
      $._hex_literal,
      $._decimal_literal,
    ),

    bool: _ => choice("true", "false"),
    "null": _ => "null",
    "self": _ => "self",

    _literal_value: $ => choice(
      $.numeric_literal,
      $.string,
      $.character,
      $.value_list,
      $.bool,
      $.null,
      $.self,
    ),

    post_op: $ => choice(
      "`", "++", "--",
      // Index operation
      seq("{", $.value, "}"),
    ),

    pre_op: _ => choice(
      "~", "-", "!", "len", "++", "--",
    ),

    bin_op: _ => choice(
      "<<", ">>",
      "*", "/", "%",
      "+", "-",
      "&", "|", "^", "!&", "!|", "!^",
      "==", "<", ">", "<==", ">==", "!==", "!<", "!>",
      "&&", "||", "^^", "!&&", "!||", "!^^",
      "=", "~=", "*=", "/=", "%=", "+=", "-=", "&=", "|=", "^=",
      "."
    ),

    value: $ => choice(
      $._literal_value,
      $.identifier,
      seq($.value, $.call_list),
      prec(3, seq($.value, $.post_op)),
      prec(2, seq($.pre_op, $.value)),
      prec.left(1, seq($.value, $.bin_op, $.value)),
    ),

    // ====
    // Stmt
    // ====

    control: $ => choice(
      seq("return", optional($.value)),
      seq("yield", optional($.value)),
      seq("break", optional($.value)),
      seq("continue", optional($.value)),
    ),

    _stmt: $ => choice(
      $.definition,
      $.value,
      $.control,
      $.asm,
    ),

    // =====
    // Extra
    // =====

    asm: $ => seq("asm", $.string),

    import_file: $ => seq(optional(":"), "import", choice($.string, $.import_string)),

    // =======
    // Comment
    // =======

    // Stolen from:
    // https://github.com/tree-sitter/tree-sitter-go/blob/2346a3ab1bb3857b48b29d779a1ef9799a248cd7/grammar.js#L926
    comment: _ => token(choice(
      seq('#', /.*/),
      seq(
        '/#',
        /[^#]*#+([^/#][^#]*#+)*/,
        '/',
      )
    )),

  },
});
