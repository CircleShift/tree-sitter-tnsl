(comment) @comment

(string) @string
(import_string) @string

(character) @character

(numeric_literal) @number

(bool) @boolean

(null) @constant
(self) @constant

(identifier) @identifier
(func_head name: (identifier) @function)

"if" @conditional
"else" @conditional
"loop" @repeat

(pre_op) @operator
(post_op) @operator
(bin_op) @operator

"continue" @keyword
"break" @keyword
"return" @keyword
"yield" @keyword

"export" @keyword
"module" @keyword

"method" @keyword

"asm" @keyword

(type name: (_) @type)
(type (identifier_qualified name: (_) @type))
(struct name: (identifier) @type)
(enum name: (identifier) @type)

"struct" @structure
"enum" @structure

