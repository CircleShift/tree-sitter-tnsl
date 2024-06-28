#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 85
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 40
#define ALIAS_COUNT 0
#define TOKEN_COUNT 22
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 8
#define PRODUCTION_ID_COUNT 1

enum ts_symbol_identifiers {
  anon_sym_SLASH_SEMI = 1,
  anon_sym_SEMI_SEMI = 2,
  anon_sym_SEMI_SLASH = 3,
  anon_sym_LPAREN = 4,
  anon_sym_RPAREN = 5,
  anon_sym_LBRACK = 6,
  anon_sym_RBRACK = 7,
  anon_sym_if = 8,
  anon_sym_else = 9,
  anon_sym_loop = 10,
  anon_sym_export = 11,
  anon_sym_module = 12,
  anon_sym_COMMA = 13,
  anon_sym_TILDE = 14,
  aux_sym_full_type_token1 = 15,
  anon_sym_BQUOTE = 16,
  sym_identifier = 17,
  sym_binary_number = 18,
  sym_octal_number = 19,
  sym_hex_number = 20,
  sym_decimal_number = 21,
  sym_top_level = 22,
  sym_top_level_block = 23,
  sym_function_inner = 24,
  sym_function_block = 25,
  sym_if_block = 26,
  sym_loop_block = 27,
  sym_module_inner = 28,
  sym_type_list = 29,
  sym_full_type = 30,
  sym_param_list = 31,
  aux_sym_top_level_repeat1 = 32,
  aux_sym_top_level_block_repeat1 = 33,
  aux_sym_function_inner_repeat1 = 34,
  aux_sym_function_block_repeat1 = 35,
  aux_sym_type_list_repeat1 = 36,
  aux_sym_full_type_repeat1 = 37,
  aux_sym_param_list_repeat1 = 38,
  aux_sym_param_list_repeat2 = 39,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_SLASH_SEMI] = "/;",
  [anon_sym_SEMI_SEMI] = ";;",
  [anon_sym_SEMI_SLASH] = ";/",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [anon_sym_LBRACK] = "[",
  [anon_sym_RBRACK] = "]",
  [anon_sym_if] = "if",
  [anon_sym_else] = "else",
  [anon_sym_loop] = "loop",
  [anon_sym_export] = "export",
  [anon_sym_module] = "module",
  [anon_sym_COMMA] = ",",
  [anon_sym_TILDE] = "~",
  [aux_sym_full_type_token1] = "full_type_token1",
  [anon_sym_BQUOTE] = "`",
  [sym_identifier] = "identifier",
  [sym_binary_number] = "binary_number",
  [sym_octal_number] = "octal_number",
  [sym_hex_number] = "hex_number",
  [sym_decimal_number] = "decimal_number",
  [sym_top_level] = "top_level",
  [sym_top_level_block] = "top_level_block",
  [sym_function_inner] = "function_inner",
  [sym_function_block] = "function_block",
  [sym_if_block] = "if_block",
  [sym_loop_block] = "loop_block",
  [sym_module_inner] = "module_inner",
  [sym_type_list] = "type_list",
  [sym_full_type] = "full_type",
  [sym_param_list] = "param_list",
  [aux_sym_top_level_repeat1] = "top_level_repeat1",
  [aux_sym_top_level_block_repeat1] = "top_level_block_repeat1",
  [aux_sym_function_inner_repeat1] = "function_inner_repeat1",
  [aux_sym_function_block_repeat1] = "function_block_repeat1",
  [aux_sym_type_list_repeat1] = "type_list_repeat1",
  [aux_sym_full_type_repeat1] = "full_type_repeat1",
  [aux_sym_param_list_repeat1] = "param_list_repeat1",
  [aux_sym_param_list_repeat2] = "param_list_repeat2",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_SLASH_SEMI] = anon_sym_SLASH_SEMI,
  [anon_sym_SEMI_SEMI] = anon_sym_SEMI_SEMI,
  [anon_sym_SEMI_SLASH] = anon_sym_SEMI_SLASH,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_LBRACK] = anon_sym_LBRACK,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
  [anon_sym_if] = anon_sym_if,
  [anon_sym_else] = anon_sym_else,
  [anon_sym_loop] = anon_sym_loop,
  [anon_sym_export] = anon_sym_export,
  [anon_sym_module] = anon_sym_module,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_TILDE] = anon_sym_TILDE,
  [aux_sym_full_type_token1] = aux_sym_full_type_token1,
  [anon_sym_BQUOTE] = anon_sym_BQUOTE,
  [sym_identifier] = sym_identifier,
  [sym_binary_number] = sym_binary_number,
  [sym_octal_number] = sym_octal_number,
  [sym_hex_number] = sym_hex_number,
  [sym_decimal_number] = sym_decimal_number,
  [sym_top_level] = sym_top_level,
  [sym_top_level_block] = sym_top_level_block,
  [sym_function_inner] = sym_function_inner,
  [sym_function_block] = sym_function_block,
  [sym_if_block] = sym_if_block,
  [sym_loop_block] = sym_loop_block,
  [sym_module_inner] = sym_module_inner,
  [sym_type_list] = sym_type_list,
  [sym_full_type] = sym_full_type,
  [sym_param_list] = sym_param_list,
  [aux_sym_top_level_repeat1] = aux_sym_top_level_repeat1,
  [aux_sym_top_level_block_repeat1] = aux_sym_top_level_block_repeat1,
  [aux_sym_function_inner_repeat1] = aux_sym_function_inner_repeat1,
  [aux_sym_function_block_repeat1] = aux_sym_function_block_repeat1,
  [aux_sym_type_list_repeat1] = aux_sym_type_list_repeat1,
  [aux_sym_full_type_repeat1] = aux_sym_full_type_repeat1,
  [aux_sym_param_list_repeat1] = aux_sym_param_list_repeat1,
  [aux_sym_param_list_repeat2] = aux_sym_param_list_repeat2,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_SLASH_SEMI] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SEMI_SEMI] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SEMI_SLASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_if] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_else] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_loop] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_export] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_module] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_TILDE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_full_type_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_BQUOTE] = {
    .visible = true,
    .named = false,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [sym_binary_number] = {
    .visible = true,
    .named = true,
  },
  [sym_octal_number] = {
    .visible = true,
    .named = true,
  },
  [sym_hex_number] = {
    .visible = true,
    .named = true,
  },
  [sym_decimal_number] = {
    .visible = true,
    .named = true,
  },
  [sym_top_level] = {
    .visible = true,
    .named = true,
  },
  [sym_top_level_block] = {
    .visible = true,
    .named = true,
  },
  [sym_function_inner] = {
    .visible = true,
    .named = true,
  },
  [sym_function_block] = {
    .visible = true,
    .named = true,
  },
  [sym_if_block] = {
    .visible = true,
    .named = true,
  },
  [sym_loop_block] = {
    .visible = true,
    .named = true,
  },
  [sym_module_inner] = {
    .visible = true,
    .named = true,
  },
  [sym_type_list] = {
    .visible = true,
    .named = true,
  },
  [sym_full_type] = {
    .visible = true,
    .named = true,
  },
  [sym_param_list] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_top_level_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_top_level_block_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_function_inner_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_function_block_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_type_list_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_full_type_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_param_list_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_param_list_repeat2] = {
    .visible = false,
    .named = false,
  },
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 30,
  [31] = 31,
  [32] = 32,
  [33] = 33,
  [34] = 34,
  [35] = 35,
  [36] = 36,
  [37] = 37,
  [38] = 38,
  [39] = 39,
  [40] = 40,
  [41] = 41,
  [42] = 42,
  [43] = 43,
  [44] = 44,
  [45] = 45,
  [46] = 46,
  [47] = 47,
  [48] = 48,
  [49] = 49,
  [50] = 50,
  [51] = 51,
  [52] = 52,
  [53] = 53,
  [54] = 54,
  [55] = 55,
  [56] = 56,
  [57] = 57,
  [58] = 58,
  [59] = 59,
  [60] = 60,
  [61] = 61,
  [62] = 62,
  [63] = 63,
  [64] = 64,
  [65] = 65,
  [66] = 66,
  [67] = 67,
  [68] = 68,
  [69] = 69,
  [70] = 70,
  [71] = 71,
  [72] = 72,
  [73] = 73,
  [74] = 74,
  [75] = 75,
  [76] = 76,
  [77] = 77,
  [78] = 78,
  [79] = 79,
  [80] = 80,
  [81] = 81,
  [82] = 82,
  [83] = 83,
  [84] = 84,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(29);
      if (lookahead == '(') ADVANCE(33);
      if (lookahead == ')') ADVANCE(34);
      if (lookahead == ',') ADVANCE(44);
      if (lookahead == '/') ADVANCE(3);
      if (lookahead == '0') ADVANCE(65);
      if (lookahead == ';') ADVANCE(2);
      if (lookahead == '[') ADVANCE(35);
      if (lookahead == ']') ADVANCE(36);
      if (lookahead == '`') ADVANCE(47);
      if (lookahead == 'e') ADVANCE(9);
      if (lookahead == 'i') ADVANCE(8);
      if (lookahead == 'l') ADVANCE(14);
      if (lookahead == 'm') ADVANCE(11);
      if (lookahead == '{') ADVANCE(21);
      if (lookahead == '~') ADVANCE(45);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(66);
      END_STATE();
    case 1:
      if (lookahead == '(') ADVANCE(33);
      if (lookahead == ')') ADVANCE(34);
      if (lookahead == ',') ADVANCE(44);
      if (lookahead == ']') ADVANCE(36);
      if (lookahead == '`') ADVANCE(47);
      if (lookahead == '{') ADVANCE(21);
      if (lookahead == '~') ADVANCE(45);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(1)
      if (lookahead != 0 &&
          (lookahead < '!' || '@' < lookahead) &&
          (lookahead < '[' || '^' < lookahead) &&
          lookahead != '|' &&
          lookahead != '}') ADVANCE(58);
      END_STATE();
    case 2:
      if (lookahead == '/') ADVANCE(32);
      if (lookahead == ';') ADVANCE(31);
      END_STATE();
    case 3:
      if (lookahead == ';') ADVANCE(30);
      END_STATE();
    case 4:
      if (lookahead == 'd') ADVANCE(20);
      END_STATE();
    case 5:
      if (lookahead == 'e') ADVANCE(38);
      END_STATE();
    case 6:
      if (lookahead == 'e') ADVANCE(42);
      END_STATE();
    case 7:
      if (lookahead == 'e') ADVANCE(57);
      if (lookahead == 'm') ADVANCE(51);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(7)
      if (lookahead != 0 &&
          (lookahead < '!' || '@' < lookahead) &&
          (lookahead < '[' || '^' < lookahead) &&
          lookahead != '`' &&
          (lookahead < '{' || '~' < lookahead)) ADVANCE(58);
      END_STATE();
    case 8:
      if (lookahead == 'f') ADVANCE(37);
      END_STATE();
    case 9:
      if (lookahead == 'l') ADVANCE(18);
      if (lookahead == 'x') ADVANCE(16);
      END_STATE();
    case 10:
      if (lookahead == 'l') ADVANCE(6);
      END_STATE();
    case 11:
      if (lookahead == 'o') ADVANCE(4);
      END_STATE();
    case 12:
      if (lookahead == 'o') ADVANCE(17);
      END_STATE();
    case 13:
      if (lookahead == 'o') ADVANCE(15);
      END_STATE();
    case 14:
      if (lookahead == 'o') ADVANCE(13);
      END_STATE();
    case 15:
      if (lookahead == 'p') ADVANCE(39);
      END_STATE();
    case 16:
      if (lookahead == 'p') ADVANCE(12);
      END_STATE();
    case 17:
      if (lookahead == 'r') ADVANCE(19);
      END_STATE();
    case 18:
      if (lookahead == 's') ADVANCE(5);
      END_STATE();
    case 19:
      if (lookahead == 't') ADVANCE(40);
      END_STATE();
    case 20:
      if (lookahead == 'u') ADVANCE(10);
      END_STATE();
    case 21:
      if (lookahead == '}') ADVANCE(46);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(21);
      END_STATE();
    case 22:
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(59);
      END_STATE();
    case 23:
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(60);
      END_STATE();
    case 24:
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(61);
      END_STATE();
    case 25:
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(62);
      END_STATE();
    case 26:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(67);
      END_STATE();
    case 27:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(63);
      END_STATE();
    case 28:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(64);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(anon_sym_SLASH_SEMI);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(anon_sym_SEMI_SEMI);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(anon_sym_SEMI_SLASH);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(anon_sym_if);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(anon_sym_else);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(anon_sym_loop);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(anon_sym_export);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(anon_sym_export);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          (lookahead < ' ' || '/' < lookahead) &&
          (lookahead < ':' || '@' < lookahead) &&
          (lookahead < '[' || '^' < lookahead) &&
          lookahead != '`' &&
          (lookahead < '{' || '~' < lookahead)) ADVANCE(58);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(anon_sym_module);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(anon_sym_module);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          (lookahead < ' ' || '/' < lookahead) &&
          (lookahead < ':' || '@' < lookahead) &&
          (lookahead < '[' || '^' < lookahead) &&
          lookahead != '`' &&
          (lookahead < '{' || '~' < lookahead)) ADVANCE(58);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(anon_sym_TILDE);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(aux_sym_full_type_token1);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(anon_sym_BQUOTE);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'd') ADVANCE(56);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          (lookahead < ' ' || '/' < lookahead) &&
          (lookahead < ':' || '@' < lookahead) &&
          (lookahead < '[' || '^' < lookahead) &&
          lookahead != '`' &&
          (lookahead < '{' || '~' < lookahead)) ADVANCE(58);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(43);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          (lookahead < ' ' || '/' < lookahead) &&
          (lookahead < ':' || '@' < lookahead) &&
          (lookahead < '[' || '^' < lookahead) &&
          lookahead != '`' &&
          (lookahead < '{' || '~' < lookahead)) ADVANCE(58);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(49);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          (lookahead < ' ' || '/' < lookahead) &&
          (lookahead < ':' || '@' < lookahead) &&
          (lookahead < '[' || '^' < lookahead) &&
          lookahead != '`' &&
          (lookahead < '{' || '~' < lookahead)) ADVANCE(58);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(48);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          (lookahead < ' ' || '/' < lookahead) &&
          (lookahead < ':' || '@' < lookahead) &&
          (lookahead < '[' || '^' < lookahead) &&
          lookahead != '`' &&
          (lookahead < '{' || '~' < lookahead)) ADVANCE(58);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(54);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          (lookahead < ' ' || '/' < lookahead) &&
          (lookahead < ':' || '@' < lookahead) &&
          (lookahead < '[' || '^' < lookahead) &&
          lookahead != '`' &&
          (lookahead < '{' || '~' < lookahead)) ADVANCE(58);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'p') ADVANCE(52);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          (lookahead < ' ' || '/' < lookahead) &&
          (lookahead < ':' || '@' < lookahead) &&
          (lookahead < '[' || '^' < lookahead) &&
          lookahead != '`' &&
          (lookahead < '{' || '~' < lookahead)) ADVANCE(58);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(55);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          (lookahead < ' ' || '/' < lookahead) &&
          (lookahead < ':' || '@' < lookahead) &&
          (lookahead < '[' || '^' < lookahead) &&
          lookahead != '`' &&
          (lookahead < '{' || '~' < lookahead)) ADVANCE(58);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(41);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          (lookahead < ' ' || '/' < lookahead) &&
          (lookahead < ':' || '@' < lookahead) &&
          (lookahead < '[' || '^' < lookahead) &&
          lookahead != '`' &&
          (lookahead < '{' || '~' < lookahead)) ADVANCE(58);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'u') ADVANCE(50);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          (lookahead < ' ' || '/' < lookahead) &&
          (lookahead < ':' || '@' < lookahead) &&
          (lookahead < '[' || '^' < lookahead) &&
          lookahead != '`' &&
          (lookahead < '{' || '~' < lookahead)) ADVANCE(58);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'x') ADVANCE(53);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          (lookahead < ' ' || '/' < lookahead) &&
          (lookahead < ':' || '@' < lookahead) &&
          (lookahead < '[' || '^' < lookahead) &&
          lookahead != '`' &&
          (lookahead < '{' || '~' < lookahead)) ADVANCE(58);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead) &&
          (lookahead < ' ' || '/' < lookahead) &&
          (lookahead < ':' || '@' < lookahead) &&
          (lookahead < '[' || '^' < lookahead) &&
          lookahead != '`' &&
          (lookahead < '{' || '~' < lookahead)) ADVANCE(58);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(sym_binary_number);
      if (lookahead == '.') ADVANCE(23);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(59);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(sym_binary_number);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(60);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(sym_octal_number);
      if (lookahead == '.') ADVANCE(25);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(61);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(sym_octal_number);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(62);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(sym_hex_number);
      if (lookahead == '.') ADVANCE(28);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(63);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(sym_hex_number);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(64);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(sym_decimal_number);
      if (lookahead == '.') ADVANCE(26);
      if (lookahead == 'B' ||
          lookahead == 'b') ADVANCE(22);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(24);
      if (lookahead == 'X' ||
          lookahead == 'x') ADVANCE(27);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(66);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(sym_decimal_number);
      if (lookahead == '.') ADVANCE(26);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(66);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(sym_decimal_number);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(67);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 1},
  [3] = {.lex_state = 1},
  [4] = {.lex_state = 1},
  [5] = {.lex_state = 1},
  [6] = {.lex_state = 0},
  [7] = {.lex_state = 1},
  [8] = {.lex_state = 1},
  [9] = {.lex_state = 1},
  [10] = {.lex_state = 1},
  [11] = {.lex_state = 1},
  [12] = {.lex_state = 1},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 1},
  [16] = {.lex_state = 1},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 1},
  [20] = {.lex_state = 0},
  [21] = {.lex_state = 0},
  [22] = {.lex_state = 0},
  [23] = {.lex_state = 0},
  [24] = {.lex_state = 0},
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 0},
  [27] = {.lex_state = 1},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 0},
  [30] = {.lex_state = 1},
  [31] = {.lex_state = 0},
  [32] = {.lex_state = 1},
  [33] = {.lex_state = 0},
  [34] = {.lex_state = 0},
  [35] = {.lex_state = 0},
  [36] = {.lex_state = 0},
  [37] = {.lex_state = 0},
  [38] = {.lex_state = 0},
  [39] = {.lex_state = 0},
  [40] = {.lex_state = 0},
  [41] = {.lex_state = 0},
  [42] = {.lex_state = 7},
  [43] = {.lex_state = 0},
  [44] = {.lex_state = 1},
  [45] = {.lex_state = 7},
  [46] = {.lex_state = 0},
  [47] = {.lex_state = 0},
  [48] = {.lex_state = 0},
  [49] = {.lex_state = 0},
  [50] = {.lex_state = 1},
  [51] = {.lex_state = 0},
  [52] = {.lex_state = 0},
  [53] = {.lex_state = 1},
  [54] = {.lex_state = 1},
  [55] = {.lex_state = 1},
  [56] = {.lex_state = 0},
  [57] = {.lex_state = 1},
  [58] = {.lex_state = 0},
  [59] = {.lex_state = 0},
  [60] = {.lex_state = 0},
  [61] = {.lex_state = 1},
  [62] = {.lex_state = 0},
  [63] = {.lex_state = 0},
  [64] = {.lex_state = 0},
  [65] = {.lex_state = 0},
  [66] = {.lex_state = 0},
  [67] = {.lex_state = 0},
  [68] = {.lex_state = 0},
  [69] = {.lex_state = 0},
  [70] = {.lex_state = 0},
  [71] = {.lex_state = 0},
  [72] = {.lex_state = 0},
  [73] = {.lex_state = 1},
  [74] = {.lex_state = 0},
  [75] = {.lex_state = 0},
  [76] = {.lex_state = 0},
  [77] = {.lex_state = 0},
  [78] = {.lex_state = 0},
  [79] = {.lex_state = 0},
  [80] = {.lex_state = 0},
  [81] = {.lex_state = 0},
  [82] = {.lex_state = 1},
  [83] = {.lex_state = 1},
  [84] = {.lex_state = 1},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_SLASH_SEMI] = ACTIONS(1),
    [anon_sym_SEMI_SEMI] = ACTIONS(1),
    [anon_sym_SEMI_SLASH] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
    [anon_sym_if] = ACTIONS(1),
    [anon_sym_else] = ACTIONS(1),
    [anon_sym_loop] = ACTIONS(1),
    [anon_sym_export] = ACTIONS(1),
    [anon_sym_module] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_TILDE] = ACTIONS(1),
    [aux_sym_full_type_token1] = ACTIONS(1),
    [anon_sym_BQUOTE] = ACTIONS(1),
    [sym_binary_number] = ACTIONS(1),
    [sym_octal_number] = ACTIONS(1),
    [sym_hex_number] = ACTIONS(1),
    [sym_decimal_number] = ACTIONS(1),
  },
  [1] = {
    [sym_top_level] = STATE(76),
    [sym_top_level_block] = STATE(51),
    [aux_sym_top_level_repeat1] = STATE(51),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_SLASH_SEMI] = ACTIONS(5),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 7,
    ACTIONS(7), 1,
      anon_sym_RPAREN,
    ACTIONS(11), 1,
      sym_identifier,
    STATE(3), 1,
      aux_sym_param_list_repeat2,
    STATE(57), 1,
      aux_sym_full_type_repeat1,
    STATE(81), 1,
      sym_param_list,
    STATE(82), 1,
      sym_full_type,
    ACTIONS(9), 2,
      anon_sym_TILDE,
      aux_sym_full_type_token1,
  [23] = 6,
    ACTIONS(11), 1,
      sym_identifier,
    ACTIONS(13), 1,
      anon_sym_RPAREN,
    STATE(5), 1,
      aux_sym_param_list_repeat2,
    STATE(57), 1,
      aux_sym_full_type_repeat1,
    STATE(82), 1,
      sym_full_type,
    ACTIONS(9), 2,
      anon_sym_TILDE,
      aux_sym_full_type_token1,
  [43] = 6,
    ACTIONS(11), 1,
      sym_identifier,
    ACTIONS(15), 1,
      anon_sym_RBRACK,
    STATE(57), 1,
      aux_sym_full_type_repeat1,
    STATE(58), 1,
      sym_full_type,
    STATE(77), 1,
      sym_type_list,
    ACTIONS(9), 2,
      anon_sym_TILDE,
      aux_sym_full_type_token1,
  [63] = 6,
    ACTIONS(17), 1,
      anon_sym_RPAREN,
    ACTIONS(22), 1,
      sym_identifier,
    STATE(5), 1,
      aux_sym_param_list_repeat2,
    STATE(57), 1,
      aux_sym_full_type_repeat1,
    STATE(82), 1,
      sym_full_type,
    ACTIONS(19), 2,
      anon_sym_TILDE,
      aux_sym_full_type_token1,
  [83] = 5,
    ACTIONS(25), 1,
      anon_sym_SLASH_SEMI,
    ACTIONS(29), 1,
      anon_sym_LPAREN,
    ACTIONS(31), 1,
      anon_sym_LBRACK,
    ACTIONS(27), 2,
      anon_sym_SEMI_SEMI,
      anon_sym_SEMI_SLASH,
    STATE(47), 2,
      sym_function_block,
      aux_sym_function_inner_repeat1,
  [101] = 6,
    ACTIONS(11), 1,
      sym_identifier,
    ACTIONS(33), 1,
      anon_sym_RBRACK,
    STATE(57), 1,
      aux_sym_full_type_repeat1,
    STATE(58), 1,
      sym_full_type,
    STATE(75), 1,
      sym_type_list,
    ACTIONS(9), 2,
      anon_sym_TILDE,
      aux_sym_full_type_token1,
  [121] = 6,
    ACTIONS(11), 1,
      sym_identifier,
    ACTIONS(35), 1,
      anon_sym_RBRACK,
    STATE(57), 1,
      aux_sym_full_type_repeat1,
    STATE(58), 1,
      sym_full_type,
    STATE(79), 1,
      sym_type_list,
    ACTIONS(9), 2,
      anon_sym_TILDE,
      aux_sym_full_type_token1,
  [141] = 3,
    ACTIONS(39), 1,
      anon_sym_COMMA,
    STATE(9), 1,
      aux_sym_param_list_repeat1,
    ACTIONS(37), 4,
      anon_sym_RPAREN,
      anon_sym_TILDE,
      aux_sym_full_type_token1,
      sym_identifier,
  [154] = 5,
    ACTIONS(11), 1,
      sym_identifier,
    STATE(57), 1,
      aux_sym_full_type_repeat1,
    STATE(58), 1,
      sym_full_type,
    STATE(78), 1,
      sym_type_list,
    ACTIONS(9), 2,
      anon_sym_TILDE,
      aux_sym_full_type_token1,
  [171] = 3,
    ACTIONS(44), 1,
      anon_sym_COMMA,
    STATE(9), 1,
      aux_sym_param_list_repeat1,
    ACTIONS(42), 4,
      anon_sym_RPAREN,
      anon_sym_TILDE,
      aux_sym_full_type_token1,
      sym_identifier,
  [184] = 3,
    ACTIONS(46), 1,
      anon_sym_LPAREN,
    ACTIONS(50), 1,
      anon_sym_BQUOTE,
    ACTIONS(48), 4,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
      anon_sym_COMMA,
      sym_identifier,
  [197] = 3,
    ACTIONS(54), 1,
      anon_sym_SLASH_SEMI,
    STATE(13), 2,
      sym_top_level_block,
      aux_sym_top_level_repeat1,
    ACTIONS(52), 3,
      ts_builtin_sym_end,
      anon_sym_SEMI_SEMI,
      anon_sym_SEMI_SLASH,
  [210] = 4,
    ACTIONS(25), 1,
      anon_sym_SLASH_SEMI,
    ACTIONS(59), 1,
      anon_sym_LBRACK,
    ACTIONS(57), 2,
      anon_sym_SEMI_SEMI,
      anon_sym_SEMI_SLASH,
    STATE(36), 2,
      sym_function_block,
      aux_sym_function_inner_repeat1,
  [225] = 3,
    ACTIONS(44), 1,
      anon_sym_COMMA,
    STATE(11), 1,
      aux_sym_param_list_repeat1,
    ACTIONS(17), 4,
      anon_sym_RPAREN,
      anon_sym_TILDE,
      aux_sym_full_type_token1,
      sym_identifier,
  [238] = 5,
    ACTIONS(11), 1,
      sym_identifier,
    STATE(57), 1,
      aux_sym_full_type_repeat1,
    STATE(58), 1,
      sym_full_type,
    STATE(74), 1,
      sym_type_list,
    ACTIONS(9), 2,
      anon_sym_TILDE,
      aux_sym_full_type_token1,
  [255] = 4,
    ACTIONS(25), 1,
      anon_sym_SLASH_SEMI,
    ACTIONS(63), 1,
      anon_sym_LBRACK,
    ACTIONS(61), 2,
      anon_sym_SEMI_SEMI,
      anon_sym_SEMI_SLASH,
    STATE(46), 2,
      sym_function_block,
      aux_sym_function_inner_repeat1,
  [270] = 4,
    ACTIONS(25), 1,
      anon_sym_SLASH_SEMI,
    ACTIONS(67), 1,
      anon_sym_if,
    ACTIONS(65), 2,
      anon_sym_SEMI_SEMI,
      anon_sym_SEMI_SLASH,
    STATE(39), 2,
      sym_function_block,
      aux_sym_function_inner_repeat1,
  [285] = 3,
    ACTIONS(69), 1,
      anon_sym_LPAREN,
    ACTIONS(73), 1,
      anon_sym_BQUOTE,
    ACTIONS(71), 4,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
      anon_sym_COMMA,
      sym_identifier,
  [298] = 4,
    ACTIONS(75), 1,
      anon_sym_if,
    ACTIONS(77), 1,
      anon_sym_else,
    ACTIONS(79), 1,
      anon_sym_loop,
    STATE(72), 2,
      sym_if_block,
      sym_loop_block,
  [312] = 3,
    ACTIONS(5), 1,
      anon_sym_SLASH_SEMI,
    ACTIONS(81), 2,
      anon_sym_SEMI_SEMI,
      anon_sym_SEMI_SLASH,
    STATE(24), 2,
      sym_top_level_block,
      aux_sym_top_level_repeat1,
  [324] = 3,
    ACTIONS(25), 1,
      anon_sym_SLASH_SEMI,
    ACTIONS(83), 2,
      anon_sym_SEMI_SEMI,
      anon_sym_SEMI_SLASH,
    STATE(34), 2,
      sym_function_block,
      aux_sym_function_inner_repeat1,
  [336] = 3,
    ACTIONS(5), 1,
      anon_sym_SLASH_SEMI,
    ACTIONS(85), 2,
      anon_sym_SEMI_SEMI,
      anon_sym_SEMI_SLASH,
    STATE(38), 2,
      sym_top_level_block,
      aux_sym_top_level_repeat1,
  [348] = 3,
    ACTIONS(5), 1,
      anon_sym_SLASH_SEMI,
    ACTIONS(85), 2,
      anon_sym_SEMI_SEMI,
      anon_sym_SEMI_SLASH,
    STATE(13), 2,
      sym_top_level_block,
      aux_sym_top_level_repeat1,
  [360] = 3,
    ACTIONS(25), 1,
      anon_sym_SLASH_SEMI,
    ACTIONS(65), 2,
      anon_sym_SEMI_SEMI,
      anon_sym_SEMI_SLASH,
    STATE(39), 2,
      sym_function_block,
      aux_sym_function_inner_repeat1,
  [372] = 3,
    ACTIONS(25), 1,
      anon_sym_SLASH_SEMI,
    ACTIONS(87), 2,
      anon_sym_SEMI_SEMI,
      anon_sym_SEMI_SLASH,
    STATE(41), 2,
      sym_function_block,
      aux_sym_function_inner_repeat1,
  [384] = 2,
    ACTIONS(91), 1,
      anon_sym_BQUOTE,
    ACTIONS(89), 4,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
      anon_sym_COMMA,
      sym_identifier,
  [394] = 3,
    ACTIONS(25), 1,
      anon_sym_SLASH_SEMI,
    ACTIONS(93), 2,
      anon_sym_SEMI_SEMI,
      anon_sym_SEMI_SLASH,
    STATE(22), 2,
      sym_function_block,
      aux_sym_function_inner_repeat1,
  [406] = 3,
    ACTIONS(25), 1,
      anon_sym_SLASH_SEMI,
    ACTIONS(93), 2,
      anon_sym_SEMI_SEMI,
      anon_sym_SEMI_SLASH,
    STATE(34), 2,
      sym_function_block,
      aux_sym_function_inner_repeat1,
  [418] = 1,
    ACTIONS(37), 5,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      anon_sym_TILDE,
      aux_sym_full_type_token1,
      sym_identifier,
  [426] = 3,
    ACTIONS(25), 1,
      anon_sym_SLASH_SEMI,
    ACTIONS(61), 2,
      anon_sym_SEMI_SEMI,
      anon_sym_SEMI_SLASH,
    STATE(46), 2,
      sym_function_block,
      aux_sym_function_inner_repeat1,
  [438] = 2,
    ACTIONS(97), 1,
      anon_sym_BQUOTE,
    ACTIONS(95), 4,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
      anon_sym_COMMA,
      sym_identifier,
  [448] = 3,
    ACTIONS(25), 1,
      anon_sym_SLASH_SEMI,
    ACTIONS(99), 2,
      anon_sym_SEMI_SEMI,
      anon_sym_SEMI_SLASH,
    STATE(29), 2,
      sym_function_block,
      aux_sym_function_inner_repeat1,
  [460] = 3,
    ACTIONS(101), 1,
      anon_sym_SLASH_SEMI,
    ACTIONS(104), 2,
      anon_sym_SEMI_SEMI,
      anon_sym_SEMI_SLASH,
    STATE(34), 2,
      sym_function_block,
      aux_sym_function_inner_repeat1,
  [472] = 3,
    ACTIONS(25), 1,
      anon_sym_SLASH_SEMI,
    ACTIONS(99), 2,
      anon_sym_SEMI_SEMI,
      anon_sym_SEMI_SLASH,
    STATE(34), 2,
      sym_function_block,
      aux_sym_function_inner_repeat1,
  [484] = 3,
    ACTIONS(25), 1,
      anon_sym_SLASH_SEMI,
    ACTIONS(106), 2,
      anon_sym_SEMI_SEMI,
      anon_sym_SEMI_SLASH,
    STATE(34), 2,
      sym_function_block,
      aux_sym_function_inner_repeat1,
  [496] = 3,
    ACTIONS(25), 1,
      anon_sym_SLASH_SEMI,
    ACTIONS(106), 2,
      anon_sym_SEMI_SEMI,
      anon_sym_SEMI_SLASH,
    STATE(35), 2,
      sym_function_block,
      aux_sym_function_inner_repeat1,
  [508] = 3,
    ACTIONS(5), 1,
      anon_sym_SLASH_SEMI,
    ACTIONS(108), 2,
      anon_sym_SEMI_SEMI,
      anon_sym_SEMI_SLASH,
    STATE(13), 2,
      sym_top_level_block,
      aux_sym_top_level_repeat1,
  [520] = 3,
    ACTIONS(25), 1,
      anon_sym_SLASH_SEMI,
    ACTIONS(110), 2,
      anon_sym_SEMI_SEMI,
      anon_sym_SEMI_SLASH,
    STATE(34), 2,
      sym_function_block,
      aux_sym_function_inner_repeat1,
  [532] = 3,
    ACTIONS(25), 1,
      anon_sym_SLASH_SEMI,
    ACTIONS(110), 2,
      anon_sym_SEMI_SEMI,
      anon_sym_SEMI_SLASH,
    STATE(43), 2,
      sym_function_block,
      aux_sym_function_inner_repeat1,
  [544] = 3,
    ACTIONS(25), 1,
      anon_sym_SLASH_SEMI,
    ACTIONS(112), 2,
      anon_sym_SEMI_SEMI,
      anon_sym_SEMI_SLASH,
    STATE(34), 2,
      sym_function_block,
      aux_sym_function_inner_repeat1,
  [556] = 4,
    ACTIONS(114), 1,
      anon_sym_export,
    ACTIONS(116), 1,
      anon_sym_module,
    ACTIONS(118), 1,
      sym_identifier,
    STATE(67), 2,
      sym_function_inner,
      sym_module_inner,
  [570] = 3,
    ACTIONS(25), 1,
      anon_sym_SLASH_SEMI,
    ACTIONS(120), 2,
      anon_sym_SEMI_SEMI,
      anon_sym_SEMI_SLASH,
    STATE(34), 2,
      sym_function_block,
      aux_sym_function_inner_repeat1,
  [582] = 4,
    ACTIONS(11), 1,
      sym_identifier,
    STATE(57), 1,
      aux_sym_full_type_repeat1,
    STATE(68), 1,
      sym_full_type,
    ACTIONS(9), 2,
      anon_sym_TILDE,
      aux_sym_full_type_token1,
  [596] = 4,
    ACTIONS(114), 1,
      anon_sym_export,
    ACTIONS(116), 1,
      anon_sym_module,
    ACTIONS(118), 1,
      sym_identifier,
    STATE(71), 2,
      sym_function_inner,
      sym_module_inner,
  [610] = 3,
    ACTIONS(25), 1,
      anon_sym_SLASH_SEMI,
    ACTIONS(57), 2,
      anon_sym_SEMI_SEMI,
      anon_sym_SEMI_SLASH,
    STATE(34), 2,
      sym_function_block,
      aux_sym_function_inner_repeat1,
  [622] = 3,
    ACTIONS(25), 1,
      anon_sym_SLASH_SEMI,
    ACTIONS(122), 2,
      anon_sym_SEMI_SEMI,
      anon_sym_SEMI_SLASH,
    STATE(34), 2,
      sym_function_block,
      aux_sym_function_inner_repeat1,
  [634] = 3,
    ACTIONS(25), 1,
      anon_sym_SLASH_SEMI,
    ACTIONS(57), 2,
      anon_sym_SEMI_SEMI,
      anon_sym_SEMI_SLASH,
    STATE(36), 2,
      sym_function_block,
      aux_sym_function_inner_repeat1,
  [646] = 4,
    ACTIONS(75), 1,
      anon_sym_if,
    ACTIONS(77), 1,
      anon_sym_else,
    ACTIONS(79), 1,
      anon_sym_loop,
    STATE(64), 2,
      sym_if_block,
      sym_loop_block,
  [660] = 3,
    ACTIONS(127), 1,
      sym_identifier,
    STATE(50), 1,
      aux_sym_full_type_repeat1,
    ACTIONS(124), 2,
      anon_sym_TILDE,
      aux_sym_full_type_token1,
  [671] = 3,
    ACTIONS(5), 1,
      anon_sym_SLASH_SEMI,
    ACTIONS(129), 1,
      ts_builtin_sym_end,
    STATE(13), 2,
      sym_top_level_block,
      aux_sym_top_level_repeat1,
  [682] = 1,
    ACTIONS(131), 4,
      ts_builtin_sym_end,
      anon_sym_SLASH_SEMI,
      anon_sym_SEMI_SEMI,
      anon_sym_SEMI_SLASH,
  [689] = 1,
    ACTIONS(133), 4,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
      anon_sym_COMMA,
      sym_identifier,
  [696] = 1,
    ACTIONS(89), 4,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
      anon_sym_COMMA,
      sym_identifier,
  [703] = 1,
    ACTIONS(48), 4,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
      anon_sym_COMMA,
      sym_identifier,
  [710] = 3,
    ACTIONS(137), 1,
      anon_sym_COMMA,
    STATE(60), 1,
      aux_sym_type_list_repeat1,
    ACTIONS(135), 2,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
  [721] = 3,
    ACTIONS(141), 1,
      sym_identifier,
    STATE(50), 1,
      aux_sym_full_type_repeat1,
    ACTIONS(139), 2,
      anon_sym_TILDE,
      aux_sym_full_type_token1,
  [732] = 3,
    ACTIONS(137), 1,
      anon_sym_COMMA,
    STATE(56), 1,
      aux_sym_type_list_repeat1,
    ACTIONS(143), 2,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
  [743] = 1,
    ACTIONS(145), 4,
      ts_builtin_sym_end,
      anon_sym_SLASH_SEMI,
      anon_sym_SEMI_SEMI,
      anon_sym_SEMI_SLASH,
  [750] = 3,
    ACTIONS(149), 1,
      anon_sym_COMMA,
    STATE(60), 1,
      aux_sym_type_list_repeat1,
    ACTIONS(147), 2,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
  [761] = 1,
    ACTIONS(152), 4,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
      anon_sym_COMMA,
      sym_identifier,
  [768] = 3,
    ACTIONS(154), 1,
      anon_sym_SEMI_SEMI,
    ACTIONS(157), 1,
      anon_sym_SEMI_SLASH,
    STATE(62), 1,
      aux_sym_top_level_block_repeat1,
  [778] = 3,
    ACTIONS(159), 1,
      anon_sym_SEMI_SEMI,
    ACTIONS(161), 1,
      anon_sym_SEMI_SLASH,
    STATE(62), 1,
      aux_sym_top_level_block_repeat1,
  [788] = 3,
    ACTIONS(163), 1,
      anon_sym_SEMI_SEMI,
    ACTIONS(165), 1,
      anon_sym_SEMI_SLASH,
    STATE(65), 1,
      aux_sym_function_block_repeat1,
  [798] = 3,
    ACTIONS(163), 1,
      anon_sym_SEMI_SEMI,
    ACTIONS(167), 1,
      anon_sym_SEMI_SLASH,
    STATE(70), 1,
      aux_sym_function_block_repeat1,
  [808] = 1,
    ACTIONS(169), 3,
      anon_sym_SLASH_SEMI,
      anon_sym_SEMI_SEMI,
      anon_sym_SEMI_SLASH,
  [814] = 3,
    ACTIONS(159), 1,
      anon_sym_SEMI_SEMI,
    ACTIONS(171), 1,
      anon_sym_SEMI_SLASH,
    STATE(63), 1,
      aux_sym_top_level_block_repeat1,
  [824] = 1,
    ACTIONS(147), 3,
      anon_sym_RPAREN,
      anon_sym_RBRACK,
      anon_sym_COMMA,
  [830] = 1,
    ACTIONS(173), 3,
      anon_sym_SLASH_SEMI,
      anon_sym_SEMI_SEMI,
      anon_sym_SEMI_SLASH,
  [836] = 3,
    ACTIONS(175), 1,
      anon_sym_SEMI_SEMI,
    ACTIONS(178), 1,
      anon_sym_SEMI_SLASH,
    STATE(70), 1,
      aux_sym_function_block_repeat1,
  [846] = 1,
    ACTIONS(157), 2,
      anon_sym_SEMI_SEMI,
      anon_sym_SEMI_SLASH,
  [851] = 1,
    ACTIONS(178), 2,
      anon_sym_SEMI_SEMI,
      anon_sym_SEMI_SLASH,
  [856] = 1,
    ACTIONS(180), 1,
      sym_identifier,
  [860] = 1,
    ACTIONS(182), 1,
      anon_sym_RPAREN,
  [864] = 1,
    ACTIONS(184), 1,
      anon_sym_RBRACK,
  [868] = 1,
    ACTIONS(186), 1,
      ts_builtin_sym_end,
  [872] = 1,
    ACTIONS(188), 1,
      anon_sym_RBRACK,
  [876] = 1,
    ACTIONS(190), 1,
      anon_sym_RPAREN,
  [880] = 1,
    ACTIONS(15), 1,
      anon_sym_RBRACK,
  [884] = 1,
    ACTIONS(192), 1,
      anon_sym_module,
  [888] = 1,
    ACTIONS(194), 1,
      anon_sym_RPAREN,
  [892] = 1,
    ACTIONS(196), 1,
      sym_identifier,
  [896] = 1,
    ACTIONS(198), 1,
      sym_identifier,
  [900] = 1,
    ACTIONS(200), 1,
      sym_identifier,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 23,
  [SMALL_STATE(4)] = 43,
  [SMALL_STATE(5)] = 63,
  [SMALL_STATE(6)] = 83,
  [SMALL_STATE(7)] = 101,
  [SMALL_STATE(8)] = 121,
  [SMALL_STATE(9)] = 141,
  [SMALL_STATE(10)] = 154,
  [SMALL_STATE(11)] = 171,
  [SMALL_STATE(12)] = 184,
  [SMALL_STATE(13)] = 197,
  [SMALL_STATE(14)] = 210,
  [SMALL_STATE(15)] = 225,
  [SMALL_STATE(16)] = 238,
  [SMALL_STATE(17)] = 255,
  [SMALL_STATE(18)] = 270,
  [SMALL_STATE(19)] = 285,
  [SMALL_STATE(20)] = 298,
  [SMALL_STATE(21)] = 312,
  [SMALL_STATE(22)] = 324,
  [SMALL_STATE(23)] = 336,
  [SMALL_STATE(24)] = 348,
  [SMALL_STATE(25)] = 360,
  [SMALL_STATE(26)] = 372,
  [SMALL_STATE(27)] = 384,
  [SMALL_STATE(28)] = 394,
  [SMALL_STATE(29)] = 406,
  [SMALL_STATE(30)] = 418,
  [SMALL_STATE(31)] = 426,
  [SMALL_STATE(32)] = 438,
  [SMALL_STATE(33)] = 448,
  [SMALL_STATE(34)] = 460,
  [SMALL_STATE(35)] = 472,
  [SMALL_STATE(36)] = 484,
  [SMALL_STATE(37)] = 496,
  [SMALL_STATE(38)] = 508,
  [SMALL_STATE(39)] = 520,
  [SMALL_STATE(40)] = 532,
  [SMALL_STATE(41)] = 544,
  [SMALL_STATE(42)] = 556,
  [SMALL_STATE(43)] = 570,
  [SMALL_STATE(44)] = 582,
  [SMALL_STATE(45)] = 596,
  [SMALL_STATE(46)] = 610,
  [SMALL_STATE(47)] = 622,
  [SMALL_STATE(48)] = 634,
  [SMALL_STATE(49)] = 646,
  [SMALL_STATE(50)] = 660,
  [SMALL_STATE(51)] = 671,
  [SMALL_STATE(52)] = 682,
  [SMALL_STATE(53)] = 689,
  [SMALL_STATE(54)] = 696,
  [SMALL_STATE(55)] = 703,
  [SMALL_STATE(56)] = 710,
  [SMALL_STATE(57)] = 721,
  [SMALL_STATE(58)] = 732,
  [SMALL_STATE(59)] = 743,
  [SMALL_STATE(60)] = 750,
  [SMALL_STATE(61)] = 761,
  [SMALL_STATE(62)] = 768,
  [SMALL_STATE(63)] = 778,
  [SMALL_STATE(64)] = 788,
  [SMALL_STATE(65)] = 798,
  [SMALL_STATE(66)] = 808,
  [SMALL_STATE(67)] = 814,
  [SMALL_STATE(68)] = 824,
  [SMALL_STATE(69)] = 830,
  [SMALL_STATE(70)] = 836,
  [SMALL_STATE(71)] = 846,
  [SMALL_STATE(72)] = 851,
  [SMALL_STATE(73)] = 856,
  [SMALL_STATE(74)] = 860,
  [SMALL_STATE(75)] = 864,
  [SMALL_STATE(76)] = 868,
  [SMALL_STATE(77)] = 872,
  [SMALL_STATE(78)] = 876,
  [SMALL_STATE(79)] = 880,
  [SMALL_STATE(80)] = 884,
  [SMALL_STATE(81)] = 888,
  [SMALL_STATE(82)] = 892,
  [SMALL_STATE(83)] = 896,
  [SMALL_STATE(84)] = 900,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_top_level, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [13] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_param_list, 1),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [17] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_param_list_repeat2, 2),
  [19] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_param_list_repeat2, 2), SHIFT_REPEAT(57),
  [22] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_param_list_repeat2, 2), SHIFT_REPEAT(19),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [27] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_inner, 1),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [35] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [37] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_param_list_repeat1, 2),
  [39] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_param_list_repeat1, 2), SHIFT_REPEAT(84),
  [42] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_param_list_repeat2, 3),
  [44] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [46] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [48] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_full_type, 2),
  [50] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [52] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_top_level_repeat1, 2),
  [54] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_top_level_repeat1, 2), SHIFT_REPEAT(42),
  [57] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_inner, 4),
  [59] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [61] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_inner, 3),
  [63] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [65] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_if_block, 1),
  [67] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [69] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [71] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_full_type, 1),
  [73] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [75] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [77] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [79] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [81] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_module_inner, 2),
  [83] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_inner, 8),
  [85] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_module_inner, 3),
  [87] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_loop_block, 1),
  [89] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_full_type, 5),
  [91] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [93] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_inner, 7),
  [95] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_full_type, 4),
  [97] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [99] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_inner, 6),
  [101] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_function_inner_repeat1, 2), SHIFT_REPEAT(49),
  [104] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_function_inner_repeat1, 2),
  [106] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_inner, 5),
  [108] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_module_inner, 4),
  [110] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_if_block, 2),
  [112] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_loop_block, 2),
  [114] = {.entry = {.count = 1, .reusable = false}}, SHIFT(80),
  [116] = {.entry = {.count = 1, .reusable = false}}, SHIFT(83),
  [118] = {.entry = {.count = 1, .reusable = false}}, SHIFT(6),
  [120] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_if_block, 3),
  [122] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_inner, 2),
  [124] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_full_type_repeat1, 2), SHIFT_REPEAT(50),
  [127] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_full_type_repeat1, 2),
  [129] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_top_level, 1),
  [131] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_top_level_block, 3),
  [133] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_full_type, 6),
  [135] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_list, 2),
  [137] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [139] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [141] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [143] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_list, 1),
  [145] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_top_level_block, 4),
  [147] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_type_list_repeat1, 2),
  [149] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_type_list_repeat1, 2), SHIFT_REPEAT(44),
  [152] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_full_type, 3),
  [154] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_top_level_block_repeat1, 2), SHIFT_REPEAT(45),
  [157] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_top_level_block_repeat1, 2),
  [159] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [161] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [163] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [165] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [167] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [169] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_block, 4),
  [171] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [173] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_block, 3),
  [175] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_function_block_repeat1, 2), SHIFT_REPEAT(20),
  [178] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_function_block_repeat1, 2),
  [180] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [182] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [184] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [186] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [188] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [190] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [192] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [194] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [196] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [198] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [200] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define TS_PUBLIC __declspec(dllexport)
#else
#define TS_PUBLIC __attribute__((visibility("default")))
#endif

TS_PUBLIC const TSLanguage *tree_sitter_TNSL() {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
