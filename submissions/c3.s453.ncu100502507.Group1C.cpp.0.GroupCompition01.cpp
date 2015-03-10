#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

enum type { ERR, ID, LPARENTHESIS, RPARENTHESIS, INUM, BLANK, NEXTLINE, END };

void proc(string&);
void stmt(string&);
void func(string &stream);
int peek(string&);
char advance(string&);
void match(string&, int);
void err();
void cleanOutFront(string&);
void display();

struct token {
	int type;
	string val;
};

vector<token> list;

int main() {
	string stream = "";

	getline(cin, stream);

	proc(stream);

	display();
	//system("pause"); //Should be deleted*********************************************************
	return 0;
}

void proc(string &stream) {
	cleanOutFront(stream);

	switch (peek(stream)) {
	case ID:
		stmt(stream);
		break;
	default:
		err();
		break;
	}
}

void stmt(string &stream) {
	cleanOutFront(stream);

	if (peek(stream) == ID) {
		match(stream, ID);
		func(stream);
	}
	else {
		err();
	}
}

void para(string &stream) {
	cleanOutFront(stream);

	switch (peek(stream)) {
	case ID:
		match(stream, ID);
		break;
	case INUM:
		match(stream, INUM);
		break;
	case RPARENTHESIS:
		break;
	default:
		err();
		break;
	}
}

void func(string &stream) {
	match(stream, LPARENTHESIS);
	para(stream);
	match(stream, RPARENTHESIS);
}

int peek(string &stream) {
	if (stream.empty()) {
		return END;
	}
	else {
		char ch = stream.at(0);

		if (ch == '(') {
			return LPARENTHESIS;
		}
		else if (ch == ')') {
			return RPARENTHESIS;
		}
		else if (isdigit(ch)) {
			return INUM;
		}
		else if (isalpha(ch)){
			return ID;
		}
		else if (ch == ' ') {
			return BLANK;
		}/*
		else if (ch == '\n') {
			return NEXTLINE;
		}*/
		else {
			return ERR;
		}
	}
}

char advance(string &stream) {
	char ch = stream.at(0);
	stream = stream.substr(1, stream.length() - 1);
	return ch;
}

void match(string &stream, int type) {
	if (!stream.empty()) {
		cleanOutFront(stream);

		token ts;
		ts.type = type;
		ts.val = "";

		switch (type) {
		case ID:
			if (isalpha(stream.at(0))) {
				while (isalpha(stream.at(0)) || stream.at(0) == '_') {
					ts.val.push_back(advance(stream));
				}
			}
			else {
				err();
			}
			break;
		case LPARENTHESIS:
			if (stream.at(0) == '(') {
				ts.val = advance(stream);
			}
			else {
				err();
			}
			break;
		case RPARENTHESIS:
			if (stream.at(0) == ')') {
				ts.val = advance(stream);
			}
			else {
				err();
			}
			break;
		case INUM:
			while (!stream.empty() && isdigit(stream.at(0))) {
				ts.val.push_back(advance(stream));
			}
			if (stream.at(0) == '.') {
				err();
			}
			break;
		default:
			err();
			break;
		}

		list.push_back(ts);
	}
	else {
		err();
	}
}

void err() {
	cout << "invalid input";
	//system("pause"); // Should be deleted************************************************************************
	exit(0);
}

void cleanOutFront(string &stream) {
	int headType = peek(stream);
	while (headType == BLANK) {
		advance(stream);
	}
}

void display() {
	token currentToken = list.at(0);

	while (!list.empty()) {
		switch (currentToken.type) {
		case ID:
			cout << "id ";
			break;
		case LPARENTHESIS:
			cout << "lparenthesis ";
			break;
		case RPARENTHESIS:
			cout << "rparenthesis ";
			break;
		case INUM:
			cout << "inum ";
			break;
		default:
			err();
			break;
		}

		cout << currentToken.val << endl;
		list.erase(list.begin());

		if (!list.empty()) {
			currentToken = list.at(0);
		}
	}
}