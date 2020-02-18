Problem Statement:

	The objective of this project is to build a lexical analyzer. This lexical analyzer will parse through an input file and extract individual lexemes and match them to tokens. These tokens consist of keywords, identifiers, operators, separators, integers, and real numbers. The lexemes to token conversion will be displayed as output to the screen. In addition, a finite state machine will also be implemented. The finite state machine will read in a string and be able to determine if it is in its final state.

How to use program:

	Type ‘make’ into the command line to compile and run program

Design of program:

	Functions:
		void printStringToken(string key, string lex)
			Prints out string token alongside its string lex value
		void printCharToken(string key, char lex)
			Prints out string token alongside its character lex value
		bool fsm(string s)
			Takes in string input and parses it using a FSM to determine if it ends on a final state
			Returns true if in the final state, false otherwise.
	Data structures:
		vector<string> keywords
			A list of certain keywords such as ‘int’, ‘bool’, ‘if’, ‘else’, ‘for’, etc.
		vector<char> separators
			A list of certain separators such as (, ), {, }, :, ;, space, etc.
		vector<char> operators
			A list of certain operators such as +, -, *, >, <, etc.
	Implementation:
		In a while loop, the program will grab each line from a text file and parse through each individual element
		For each element, the program will check whether the variable is a letter, digit, separator, or operator.
		When a separator/operator is found, the program will check if there is a running identifier (if the string for an identifier is not empty) and compare it with the list of keywords.
		The program will continuously print tokens and lexeme matches until the end of the file is reached
	Finite State Machine:
		Table Implementation:
			int fsmTable[14][12]
			Rows represent states (1 - 14),  Columns represent identifiers
		DFSM = (Sigma, Q, q0, F, N):
			Sigma = {1, d, ), (, }, {, [, ], !, ., sp, p}
			Q = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14}
			q0 = 1
			F = { 3, 5, 7, 9, 11, 13, 14}

		bool fsm(string s)
			Defines fsmTable 2D array with values for state changes
			Compares each character of string input with each column
			Changes state where row = currentstate and column = index of token
			Returns true when the end state is a final state, false otherwise

Limitation:

	None

Shortcomings:

	None

