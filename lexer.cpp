#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cctype>

using namespace std;

// prints string tokens & lexemes
void printStringToken(string key, string lex);

// prints string tokens & char lexemes
void printCharToken(string key, char lex);

int main() {

	// set of keywords
	vector<string> keywords = {"int", "float", "bool", "true", 
		"false", "if", "else", "then", "endif", "while", "whileend",
		"do", "doend", "for", "forend", "input", "output", "and",
		"or", "not"};

	// set of separators
	vector<char> separators = {'\'', '(' , ')', '{', '}', '[', ']', 
		',', '.', ':', ';', ' '};

	// set of operators
	vector<char> operators = {'+', '*', '-','/', '=', '>', '<', '%'};

	vector<string> lexemes;

	cout << "TOKEN\t\t\tLEXEME" << endl << endl;

	ifstream sourceCode;
	sourceCode.open("sourceCode.txt");
	string line;
	string identifier = "";
	string number = "";
	string type;

	// parse file for tokens/lexemes
	while (getline(sourceCode, line)) {
	
		for (string::iterator i = line.begin(); i != line.end(); i++) {
			
			// checks if character is alphabetic
			if (isalpha(*i)) {
				identifier = identifier + *i;
			}

			// checks if character is a digit
			else if (isdigit(*i)) {
				if (identifier.compare("") == 0) {
					number += *i;
				}
				else {
					identifier = identifier + *i;
				}
			}

			// checks if character is a separator
			// this ends up resetting the identifier
			for (vector<char>::iterator s = separators.begin(); s != separators.end(); s++) {
				if (*s == *i) {

					// method to print identifier / keyword when separator is found
					if (identifier.compare("") != 0) {
						 
						 type = "IDENTIFIER";

						 // search for keyword match
						 for (vector<string>::iterator k = keywords.begin(); k != keywords.end(); k++) {
							 if (identifier.compare(*k) == 0) {
								 type = "KEYWORD\t";
							 }
						 }
						 
						 printStringToken(type, identifier);
	                                         identifier = "";
					}

					// method to print number when separator is found
					else if (number.compare("") != 0) {

						// checks for real vs integer number
						if (*i == '.') {
							type = "REAL\t";
							number = number + *i;
						}
						else {
							if (type.compare("REAL\t") != 0) {
								type = "INTEGER\t";
							}
							printStringToken(type, number);
							number = "";
							type = "";
						}
					
					}
					// checks for spaces and if we are parsing a real number
					if (*i != ' ' && type.compare("REAL\t") != 0) {
						type = "SEPARATOR";
						printCharToken(type, *i);
					}
				}
			}

			//checks if character is an operator
			for (vector<char>::iterator o = operators.begin(); o != operators.end(); o++) {
				if (*o == *i) {

					// method to print identifer / keyword when operator is found
					if (identifier.compare("") != 0) {
                                                
                                                 type = "IDENTIFIER";

						 // search for keyword match
                                                 for (vector<string>::iterator k = keywords.begin(); k != keywords.end(); k++) {
                                                         if (identifier.compare(*k) == 0) {
                                                                 type = "KEYWORD\t";
                                                         }
                                                 }
                                                 printStringToken(type, identifier);
                                                 identifier = "";
                                        }
					
					// method to print number when separator is found
                                        else if (number.compare("") != 0) {

                                                type = "INTEGER\t";
                                                printStringToken(type, number);
						number = "";

                                        }

					type = "OPERATOR";
					printCharToken(type, *i);
				}
			}
		}
	}

	return 0;
}

void printStringToken(string key, string lex) {
	cout << key << "\t=\t" << lex << endl;
}

void printCharToken(string key, char lex) {
	cout << key << "\t=\t" << lex << endl;
}

