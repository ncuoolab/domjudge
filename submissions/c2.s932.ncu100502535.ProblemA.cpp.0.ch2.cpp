#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

bool Proc();
bool Stmt();
bool Val();
bool Id();
bool Assign();
bool Inum();

bool isNumber(string& input);

vector<string> tokens;
string output = "";

int main() {
	string line;
	getline(cin, line);
	string token;
	stringstream ss(line);
	while(ss >> token) {
		tokens.push_back(token);
	}

	if (Proc()) {
		cout << output;
	} else {
		cout << "valid input";
	}

	system("pause");
	return 0;
}

bool Proc() {
	return Stmt();
}

bool Stmt() {
	return Id() && Assign() && Val();
}

bool Val() {
	return Id() || Inum();
}

bool Id() {
	if (tokens.size() > 0) {
		string token = tokens.front();
		if (token.length() == 1 && token.at(0) >= 'a' && token.at(0) <= 'z') {
			output += "id " + token + "\n";
			tokens.erase(tokens.begin());
			return true;
		}
	}
	return false;
}

bool Assign() {
	if (tokens.size() > 0) {
		string token = tokens.front();
		if (token.length() == 1 && token.at(0) == '=') {
			output += "assign " + token + "\n";
			tokens.erase(tokens.begin());
			return true;
		}
	}
	return false;
}

bool Inum() {
	if (tokens.size() > 0) {
		string token = tokens.front();
		if (isNumber(token)) {
			output += "inum " + token + "\n";
			tokens.erase(tokens.begin());
			return true;
		}
	}
	return false;
}

bool isNumber(string& input) {
	for (int i = 0; i < input.length(); i++) {
		if (input.at(i) < '0' || input.at(i) > '9') {
			return false;
		}
	}
	return true;
}