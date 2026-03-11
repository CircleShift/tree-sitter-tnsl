/**
 * @file TNSL Language Parser
 * @author Kai Gunger <kgunger@gmail.com>
 * @license MIT
 */

/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

// Whitespace and newlines
const NL = new RustRegex("[\\r\\n]");
const NL_ = new RustRegex("[\\r\\n]+");
const _NL = optional(NL_);
const WS = new RustRegex("[\\s&&[^\\r\\n]]");
const BLOCK_SEP = choice(";;", seq( ";/", _NL, "/;" ));

// Used when defining identifiers
const ANTI_RESERVED = '[^`~!@#$%^&*()\\-=+\\[\\]{}\\\\|;:\'",<.>/?]';

module.exports = grammar({
  name: "tnsl",

  extras: $ => [WS],

  conflicts: $ => [
    [$._type_prefix, $.pre_op],
    [$.value, $.identifier_qualified],
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
      NL_,

      $.struct,
      $.enum_def,
      $.import_file,
      $.asm,
      $.definition,

      $.mod_block,
    ),

    mod_head: $ => seq(
      optional("export"), "module", $.identifier,
    ),

    mod_body: $ => seq(
      NL, repeat($._mod_stmt),
    ),

    module: $ => seq(
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
      $.function_def,
      // Sub-module
      $.module,
      // Method definition
      $.method,
    ),

    // =================
    // Method definition
    // =================

    _method_stmt: $ => choice(
      NL_,

      $._method_block,
    ),

    method_head: $ => seq(
      "method", $.identifier_qualified,
    ),

    method_body: $ => seq(
      NL, repeat($._method_stmt),
    ),

    method: $ => seq(
      $.method_head, optional($.method_body),
    ),

    _method_block: $ => seq(
      "/;", $._method_block_inner,
      repeat(seq(
        ";;", $._method_block_inner,
      )),
      ";/",
    ),

    _method_block_inner: $ => choice(
      $.function_def,
      $._operator_function
    ),

    _operator_function: $ => seq(
      "operator", _NL
    ),

    // =================
    // Struct definition
    // =================

    struct: $ => seq(
      "struct", $.identifier, _NL, optional($.parameter_list), _NL, $.struct_def_list
    ),

    struct_def_list: $ => seq(
      "{", _NL,
      optional(seq(
        $.type, _NL, $.identifier, _NL,
        repeat(seq(
          ",", _NL, optional($.type), _NL, $.identifier, _NL
        )),
      )),
      "}",
    ),

    // ===============
    // Enum definition
    // ===============

    enum_def: $ => seq(
      "enum", $.identifier, _NL, optional($.type_list), _NL, $.enum_def_list
    ),

    enum_def_list: $ => seq(
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

    _func_stmt: $ => choice(
      NL_,

      seq($._stmt, NL),

      seq($._func_block, NL),
    ),

    func_head: $ => seq(
      $.identifier, optional($.parameter_list), optional($.type_list),
    ),

    func_body: $ => seq(
      NL, repeat($._func_stmt),
    ),

    function_def: $ => seq(
      $.func_head, optional($.func_body),
    ),

    _func_block: $ => seq(
      "/;", $._func_block_inner,
      repeat(seq(
        ";;", $._func_block_inner,
      )),
      ";/",
    ),

    _func_block_inner: $ => choice(
      $.if_block,
      $.loop_block,
      $.function_def,
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
          ",", _NL, optional($.type), _NL, $.identifier, _NL,
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

    _type_prefix: $ => choice(
      "~", $._type_prefix_array,
    ),

    _type_postfix: _ => choice(
      "`",
    ),

    type: $ => prec.right(1, seq(
      repeat($._type_prefix),
      choice(
        seq($.identifier_qualified, optional($.call_list)),
        seq("void", optional($.call_list), optional($.type_list)),
        seq("yield", $.type_list)
      ),
      repeat($._type_postfix),
    )),

    // ======
    // Values
    // ======

    identifier: _ => new RustRegex(`[\\S&&${ANTI_RESERVED}&&[^0-9]][\\S&&${ANTI_RESERVED}]*`),

    identifier_qualified: $ => prec.right(seq(
      $.identifier, repeat(seq(".", _NL, $.identifier)),
    )),

    escape: _ => new RustRegex("\\\\[^u]|\\\\u[0-9a-fA-F]+"),

    string: $ => seq(
      "\"",
      repeat(choice(
        new RustRegex('[^"\\\\]'),
        $.escape,
      )),
      "\"",
    ),

    import_string: $ => seq(
      "\'",
      repeat(choice(
        new RustRegex("[^'\\\\]"),
        $.escape,
      )),
      "\'",
    ),

    character: $ => seq(
      "\'",
      choice(
        new RustRegex("[^'\\\\]"),
        $.escape,
      ),
      "\'",
    ),

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

    _literal_value: $ => choice(
      $.numeric_literal,
      $.string,
      $.character,
      $.value_list,
    ),

    post_op: $ => choice(
      "`", "++", "--",
      // Get operation
      seq(".", _NL, $.identifier),
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
    ),

    value: $ => choice(
      $._literal_value,
      $.identifier,
      seq($.value, $.call_list),
      prec(3, seq($.value, $.post_op)),
      prec(2, seq($.pre_op, $.value)),
      prec.left(1, seq($.value, $.bin_op, $.value)),
      prec(1, $.type),
    ),

    // ====
    // Stmt
    // ====

    control: $ => choice(
      seq("return", $.value),
      seq("yield", optional($.value)),
      seq("break", optional($.value)),
      seq("continue", optional($.value)),
    ),

    _stmt: $ => choice(
      NL,
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
  }
});
