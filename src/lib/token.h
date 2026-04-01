#ifndef MINIC_TOKEN_H
#define MINIC_TOKEN_H

#include <string>

enum class token_type {
	SEMICOLON,
	OP_BRACE, CL_BRACE,
	OP_PAREN, CL_PAREN,
	// OP_BRACKET, CL_BRACKET,
	KEYWORD,
	IDENTIFIER,
	CONST
};
enum class const_type {
	UNDEFINED, 
	INT
};
struct token {
	token_type type;
	const_type ctype = const_type::UNDEFINED;
	std::string name;
};

std::string token_type_decode(token_type);
std::string const_type_decode(const_type);
std::ostream& operator<<(std::ostream&, const token&);

#endif