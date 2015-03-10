#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <regex.h>

using namespace std;

void Proc();
void Dcl();
void Id();
void Stmt();
void error();
string removeSpaces(string&);

char* level = "^[\\s]*l[0-9]+";
char* FirstName = "^[\\s]*[A-Z][a-z]*";
char* LastName = "^[\\s]*[a|c-z]+";
char* cid = "^[\\s]*[0-9]+";
char* battle = "^[\\s]*b";

const int MAX_SIZE = 1024;

char input[MAX_SIZE];
string output = "";
regex_t preg;
int rc;
int nmatch = 2;
regmatch_t pmatch[2];

int main() {
	cout << "Input: ";
	cin.getline(input, MAX_SIZE);

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
	regcomp(&preg, level, 0);
	if (0 != (rc = regexec(&preg, input, nmatch, pmatch, 0))) {
		string s = string(input).substr(pmatch[0].rm_so, pmatch[0].rm_so - pmatch[0].rm_eo);
		int match_length = pmatch[0].rm_so - pmatch[0].rm_eo;
		s = removeSpaces(s);
		output += "level " + s + "\n";
		input += pmatch[0].rm_so - pmatch[0].rm_eo;
	} else {
		error();
	}
	Id();
}

void Id() {
	regcomp(&preg, cid, 0);
	if (0 != (rc = regexec(&preg, input, nmatch, pmatch, 0))) {
		string s = string(input).substr(pmatch[0].rm_so, pmatch[0].rm_so - pmatch[0].rm_eo);
		int match_length = pmatch[0].rm_so - pmatch[0].rm_eo;
		s = removeSpaces(s);
		output += "cid " + s + "\n";
		input += pmatch[0].rm_so - pmatch[0].rm_eo;
	} else {	
		regcomp(&preg, FirstName, 0);
		if (0 != (rc = regexec(&preg, input, nmatch, pmatch, 0))) {
			string s = string(input).substr(pmatch[0].rm_so, pmatch[0].rm_so - pmatch[0].rm_eo);
			int match_length = pmatch[0].rm_so - pmatch[0].rm_eo;
			s = removeSpaces(s);
			output += "FirstName " + s + "\n";
			input += pmatch[0].rm_so - pmatch[0].rm_eo;
			regcomp(&preg, LastName, 0);
			if (0 != (rc = regexec(&preg, input, nmatch, pmatch, 0))) {
				string s = string(input).substr(pmatch[0].rm_so, pmatch[0].rm_so - pmatch[0].rm_eo);
				int match_length = pmatch[0].rm_so - pmatch[0].rm_eo;
				s = removeSpaces(s);
				output += "LastName " + s + "\n";
				input += pmatch[0].rm_so - pmatch[0].rm_eo;
			} else {
				error();
			}
		} else {
			error();
		}
	}
}

void Stmt() {
	regcomp(&preg, battle, 0);
	if (0 != (rc = regexec(&preg, input, nmatch, pmatch, 0))) {
		string s = string(input).substr(pmatch[0].rm_so, pmatch[0].rm_so - pmatch[0].rm_eo);
		int match_length = pmatch[0].rm_so - pmatch[0].rm_eo;
		s = removeSpaces(s);
		output += "battle " + s + "\n";
		input += pmatch[0].rm_so - pmatch[0].rm_eo;
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
	while(s.at(0) == ' ') {
		s = s.substr(1, s.length() - 1);
	}
	return s;
}