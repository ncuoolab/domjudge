#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

enum type {ERR, ID, ASSIGN, INUM};

void proc(string);
void stmt(string);
void val();
int scannDigit(string);
int scannID(string);
int peek(string);
bool eof(string&);
void advance(string&);

struct token {
	int type;
	string val;
};

int main() {
	string stream = "";
	cout << "$ ";
	getline(cin, stream);

	cout << stream;
	system("pause");
	return 0;
}

void proc(string stream) {

}

void stmt(string stream) {

}

void val() {

}

int peek(string stream) {
	char ch = stream.begin;

	if (ch == '=') {
		return ASSIGN;
	}
	else if (isdigit(ch)) {
		return INUM;
	}
	else {
		return ID;
	}
}

void advance(string &stream) {
	stream = stream.substr(1, stream.length-1);
}

bool eof(string &stream) {
	if (stream == "") {
		return true;
	}
	else {
		return false;
	}
}

int scannDigit(string stream) {
	
}

int scannID(string stream) {

}