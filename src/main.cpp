#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstdio>

#include "lexer/lexer.h"
#include "parser/parser.h"
#include "code/code_gen.h"
#include "asm/asm_gen.h"

int main(int argc, char** argv) {
	if(argc < 2) {
		// std::printf("\n");
		// std::printf("\x1B[31mTexting\033[0m\t\t");
		// std::printf("\x1B[32mTexting\033[0m\t\t");
		// std::printf("\x1B[33mTexting\033[0m\t\t");
		// std::printf("\x1B[34mTexting\033[0m\t\t");
		// std::printf("\x1B[35mTexting\033[0m\n");
		
		// std::printf("\x1B[36mTexting\033[0m\t\t");
		// std::printf("\x1B[36mTexting\033[0m\t\t");
		// std::printf("\x1B[36mTexting\033[0m\t\t");
		// std::printf("\x1B[37mTexting\033[0m\t\t");
		// std::printf("\x1B[93mTexting\033[0m\n");
		
		// std::printf("\033[3;42;30mTexting\033[0m\t\t");
		// std::printf("\033[3;43;30mTexting\033[0m\t\t");
		// std::printf("\033[3;44;30mTexting\033[0m\t\t");
		// std::printf("\033[3;104;30mTexting\033[0m\t\t");
		// std::printf("\033[3;100;30mTexting\033[0m\n");

		// std::printf("\033[3;47;35mTexting\033[0m\t\t");
		// std::printf("\033[2;47;35mTexting\033[0m\t\t");
		// std::printf("\033[1;47;35mTexting\033[0m\t\t");
		// std::printf("\t\t");
		// std::printf("\n");
		std::cout << "pc: \x1B[31merror\033[0m: no file given" << std::endl;
		return -1;
	} else {}
	std::string fin, filename;
	if(argc == 2) {
		fin = argv[1];
		filename = argv[1];
	}
	std::system(("clang++ " + fin + "").c_str());
	std::system(("as -s " + filename + ".s -o" + filename + ".o").c_str());
	std::system(("clang++ " + filename + ".o -o" + filename).c_str());
	return 0;
}