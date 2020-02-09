#include <iostream>
#include <string>
#include <vector>
#include <fstream>

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
	string::iterator i;
	while (!sourceCode.eof()) {
		getline(sourceCode, line);
	}


	return 0;
}
