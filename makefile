objects = src/lexer/lexer.o src/parser/parser.o src/asm/asm_gen.o src/code/code_gen.o src/main.o

all: $(objects)
	$(CXX) $(LDFLAGS) $^ $(LDLIBS) -o pc
	chmod +x pc 

CXX = clang++
CXXFLAGS = -std=c++20 -stdlib=libc++ -O2 -Wall -fcolor-diagnostics -fansi-escape-codes -I./src

%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $^ -o $@

clean:
	find . -name "*.o" -type f -delete