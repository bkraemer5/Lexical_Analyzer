all: program1
	./lexer

program1: lexer.cpp
	g++ -o lexer lexer.cpp
