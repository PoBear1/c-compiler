#ifndef _C_COMPILER_LEXER_
#define _C_COMPILER_LEXER_
#include <lib/token.h>
#include <string>
#include <vector>

class lexer {
public:
	// lexer(std::string);
	int run_lexer(std::string);
	const std::vector<token>& tokened_code() {return v;}
private:
	std::vector<token> v;
	int match_single_char(char c);
	int isword(char c);
#define num_keywords 3
	const std::string keywords[num_keywords] = {
		std::string("int"),
		std::string("void"),
		std::string("return")
	};
};

#endif