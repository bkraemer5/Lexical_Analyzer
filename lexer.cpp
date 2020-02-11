#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cctype>

using namespace std;



int main() {

	vector<string> keywords = {"int", "float", "bool", "true", 
		"false", "if", "else", "then", "endif", "while", "whileend",
		"do", "doend", "for", "forend", "input", "output", "and",
		"or", "not"};
	vector<char> separators = {'\'', '(' , ')', '{', '}', '[', ']', 
		',', '.', ':', ';', ' '};
	vector<char> operators = {'+', '*', '-','/', '=', '>', '<', '%'};


	ifstream sourceCode;
	sourceCode.open("sourceCode.txt");
	string line;
	string identifier;
	string number;
	while (!sourceCode.eof()) {
		getline(sourceCode, line);
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
				cout << *i << " ";
			}

			// checks if character is a separator
			// this ends up resetting the identifier
			for (vector<char>::iterator s = separators.begin(); s != separators.end(); s++) {
				if (*s == *i) {
					cout << identifier << " ";
					identifier = "";
					cout << *s;
				}
			}

			//checks if character is an operator
			for (vector<char>::iterator o = operators.begin(); o != operators.end(); o++) {
				if (*o == *i) {
					cout << identifier << " ";
					identifier = "";
					cout << *o << " ";
				}
			}
		}
		cout << endl;
	}

	return 0;
}
