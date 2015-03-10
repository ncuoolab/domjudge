#include <cstdlib>
#include <iostream>
#include <string>
#include <regex>
#include <algorithm>

using namespace std;

void Proc();
void Dcl();
void Id();
void Stmt();
void error();
string removeSpaces(string&);

regex level("^[\\s]*l[0-9]+");
regex FirstName("^[\\s]*[A-Z][a-z]*");
regex LastName("^[\\s]*[a|c-z]+");
regex cid("^[\\s]*[0-9]+");
regex battle("^[\\s]*b");

const int MAX_SIZE = 1024;

string input, output = "";
int p = 0;

int main() {
	cout << "Input: ";
	char inputChar[MAX_SIZE];
	cin.getline(inputChar, MAX_SIZE);
	input = string(inputChar);

	Proc();
	cout << output;

	system("pause");
	return 0;
}

void Proc() {
	Dcl();
	Stmt();
}

void Dcl() {
	smatch match;
	if (regex_search(input, match, level)) {
		string s = match[0].str();
		int match_length = match[0].str().length();
		s = removeSpaces(s);
		output += "level " + s + "\n";
		input = input.substr(match_length, input.length() - match_length);
	} else {
		error();
	}
	Id();
}

void Id() {
	smatch match;
	if (regex_search(input, match, cid)) {
		string s = match[0].str();
		int match_length = match[0].str().length();
		s = removeSpaces(s);
		output += "cid " + s + "\n";
		input = input.substr(match_length, input.length() - match_length);
	} else if (regex_search(input, match, FirstName)) {
		string s = match[0].str();
		int match_length = match[0].str().length();
		s = removeSpaces(s);
		output += "FirstName " + s + "\n";
		input = input.substr(match_length, input.length() - match_length);
		if (regex_search(input, match, LastName)) {
			string s = match[0].str();
			int match_length = match[0].str().length();
			s = removeSpaces(s);
			output += "LastName " + s + "\n";
			input = input.substr(match_length, input.length() - match_length);
		} else {
			error();
		}
	} else {
		error();
	}
}

void Stmt() {
	smatch match;
	if (regex_search(input, match, battle)) {
		string s = match[0].str();
		int match_length = match[0].str().length();
		s = removeSpaces(s);
		output += "battle " + s + "\n";
		input = input.substr(match_length, input.length() - match_length);
		Id();
	} else {
		error();
	}
}

void error() {
	cout << "invalid input\n";
	system("pause");
	exit(1);
}

string removeSpaces(string& s) {
    regex rgx("[\\s]*"); 
	return regex_replace(s, rgx, string(""));
}