#include <ostream>
#include <string>
#include "token.h"

std::string token_type_decode(token_type t_type) {
	switch(t_type) {
	case token_type::SEMICOLON:
		return "SEMICOLON";
		break;
	case token_type::OP_BRACE:
		return "OP_BRACE";
		break;
	case token_type::CL_BRACE:
		return "CL_BRACE";
		break;
	case token_type::OP_PAREN:
		return "OP_PAREN";
		break;
	case token_type::CL_PAREN:
		return "CL_PAREN";
		break;
	case token_type::KEYWORD:
		return "KEYWORD";
		break;
	case token_type::IDENTIFIER:
		return "IDENTIFIER";
		break;
	case token_type::CONST:
		return "CONST";
		break;
	default:
		return "";
		break;
	}
}

std::string token_type_decode(const_type t_type) {
	switch(t_type) {
	case const_type::UNDEFINED:
		return "UNDEFINED";
		break;
	case const_type::INT:
		return "INT";
		break;
	default:
		return "";
		break;
	}
}

std::ostream& operator<<(std::ostream& fout, const token& tok) {
	fout << "(" << token_type_decode(tok.type) << ", \"" << tok.name << "\", token type: " << token_type_decode(tok.ctype) << ")";
	return fout;
}