#ifndef _C_COMPILER_LEXER_
#define _C_COMPILER_LEXER_
#include <string>
#include <vector>

struct token {

};
enum class token_t {
	
};
class lexer {
private:
	static const std::vector<std::string> keyword_list;
public:
	lexer(); 
};
#endif