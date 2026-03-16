(comment) @comment

(string) @string
(import_string) @string

(character) @character

(numeric_literal) @number

(bool) @boolean

(null) @constant.builtin
(self) @variable.builtin

(func_head name: (identifier) @function)

(pre_op) @operator
(post_op) @operator
(bin_op) @operator
(type_prefix) @operator
(type_postfix) @operator
(type "." @operator)

(call_list) @operator

(identifier) @identifier
(value (identifier)) @variable
(parameter_list (identifier)) @variable
(struct_data_list (identifier)) @variable
(definition (identifier)) @variable


(value (value
	(identifier) @function)
	(call_list))

(value (value
	(value (identifier) @function) .)
	(call_list))

"true" @constant.builtin
"false" @constant.builtin

"if" @keyword.conditional
"else" @keyword.conditional
"loop" @keyword.repeat

"continue" @keyword
"break" @keyword
"return" @keyword.return
"yield" @keyword.return

"export" @keyword
"module" @keyword.modifier

"method" @keyword

"asm" @keyword

(type name: (_) @type)
(struct name: (identifier) @type)
(enum name: (identifier) @type)

"struct" @keyword.type
"enum" @keyword.type

