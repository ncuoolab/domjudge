#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

enum type {ERR, ID, ASSIGN, INUM, END};

void proc(string&);
void stmt(string&);
void val(string &);
int peek(string);
char advance(string&);
void match(string&, int);
void err();
void display();

struct token {
	int type;
	string val;
};

vector<token> list;

int main() {
	string stream = "";

	cout << "$ ";
	getline(cin, stream);
	
	proc(stream);

	display();
	system("pause");
	return 0;
}

void proc(string &stream) {
	switch (peek(stream)) {
	case ID:
		stmt(stream);
		break;
	case END:
		break;
	case ERR:
	default:
		err();
		break;
	}
}

void stmt(string &stream) {
	if (peek(stream) == INUM) {
		match(stream, ID);
		match(stream, ASSIGN);
		val(stream);
	}
	else {
		err();
	}
}

void val(string &stream) {
	switch (peek(stream)) {
	case ID:
		match(stream, ID);
		break;
	case INUM:
		match(stream, INUM);
		break;
	default:
		err();
		break;
	}
}

int peek(string stream) {
	char ch = stream.front();

	if (ch == '=') {
		return ASSIGN;
	}
	else if (isdigit(ch)) {
		return INUM;
	}
	else if (isalpha(ch)){
		return ID;
	}
	else if (ch == EOF) {
		return END;
	}
	else {
		return ERR;
	}
}

char advance(string &stream) {
	char ch = stream.front();
	stream = stream.substr(1, stream.length()-1);
	return ch;
}

void match(string &stream, int type) {
	token ts;
	ts.type = type;
	ts.val = "";
	
	switch (type) {
	case ID:
		if (isalpha(peek(stream))) {
			ts.val = advance(stream);
		}
		else {
			err();
		}
	case ASSIGN:
		if (stream.front() == '=') {
			ts.val = advance(stream);
		}
		else {
			err();
		}
		break;
	case INUM:
		char ch;
		while (isdigit(ch = advance(stream))) {
			ts.val.push_back(ch);
		}
		break;
	default:
		err();
		break;
	}

	list.push_back(ts);
}

void err() {
	cerr << "Valid input\n";
	system("pause");
	exit(1);
}

void display() {	
	token currentToken = list.front();

	while (!list.empty()) {
		switch (currentToken.type) {
		case ID:
			cout << "id ";
			break;
		case ASSIGN:
			cout << "assign ";
			break;
		case INUM:
			cout << "inum ";
			break;
		default:
			err();
			break;
		}
	}

	cout << currentToken.val << endl;
}