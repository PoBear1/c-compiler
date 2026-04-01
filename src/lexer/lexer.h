#ifndef _C_COMPILER_LEXER_
#define _C_COMPILER_LEXER_
#include <string>
#include <vector>

struct token {
	std::string tok;
	token_t ttype;
};
enum class token_t {
	ID, KEYWORD, CONST, OP, 
	OP_PAREN, CL_PAREN,
	OP_BLOCK, CL_BLOCK,
	OP_BRACE, CL_BRACE,
	SEMICOLON
};
class lexer {
private:
	inline static const std::vector<std::string> keyword_list = {
		"auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", "extern", "float", "for", "goto", "if", "inline", "int", "long", "register", "restrict", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"
	};
public:
	lexer(); 

};
#endif