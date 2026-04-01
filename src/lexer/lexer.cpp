#include <error_codes.h>
#include <iostream>
#include "lexer.h"
#include <cctype>

int lexer::match_single_char(char c) {
	token t;
	switch(c) {
	case '{':
		t.type = token_type::OP_BRACE;
		t.name = "{";
		break;
	case '}':
		t.type = token_type::CL_BRACE;
		t.name = "}";
		break;
	case '(':
		t.type = token_type::OP_PAREN;
		t.name = "(";
		break;
	case ')':
		t.type = token_type::CL_PAREN;
		t.name = ")";
		break;
	default:
		return 1;
	}
	v.push_back(t);
	return 0;
}

int lexer::isword(char c) {return isalnum(c) | (c == '_');}

int lexer::run_lexer(std::string s) {
	std::string::iterator it = s.begin();
	token t;
	while(it != s.end()) {
		if(*it == ' ' || *it == '\t' || *it == '\n') {++it; continue;}
		if(*it == ';') {
			t.type = token_type::SEMICOLON;
			t.name = ";";
			v.push_back(t); 
			++it; continue;
		}
		if(*it == '/' && it + 1 != s.end() && *(it + 1) == '/') {
			while(++it != s.end() && *it != '\n') {}
			continue;
		}
		if(*it == '/' && it + 1 != s.end() && *(it + 1) == '*') {
			while(++it != s.end() && (it + 1) != s.end() && (*it != '*' || *(it + 1) != '/')) {}
			it += 2; 
			continue;
		}
		if(match_single_char(*it) != 0) {
			// we are in the keyword, identifier or constant category
			// first match constants to get them out of the way
			if(isdigit(*it)) {
				std::string::iterator start_p = it;
				while(++it != s.end() && isdigit(*it)) {}
				if(isword(*it)) {return LEX_UNKNOWN_TOKEN;} else {}
				t.type = token_type::CONST;
				t.name = std::string(start_p, it);
				t.ctype = const_type::INT;
			} else if(isalpha(*it) || *it == '_'){
				std::string::iterator start_p = it;
				while(++it != s.end() && isword(*it)) {}
				t.type = token_type::IDENTIFIER;
				t.name = std::string(start_p, it);
				for(int i = 0; i < num_keywords; ++i) {
					if(t.name == keywords[i]) {t.type = token_type::KEYWORD; break;}
				}
			} else {
				return 1;
			}
			v.push_back(t);
			t.ctype = const_type::UNDEFINED;
		} else {++it;}
	}
	return LEX_SUCCESS;
}

