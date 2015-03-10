#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

enum type { ERR, ID, ASSIGN, INUM, BLANK, END };

void proc(string&);
void stmt(string&);
void val(string &);
int peek(string&);
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

	getline(cin, stream);

	proc(stream);

	display();
	system("pause");
	return 0;
}

void proc(string &stream) {
	while (peek(stream) == BLANK) {
		advance(stream);
	}

	switch (peek(stream)) {
	case ID:
		stmt(stream);
		break;
	default:
		err();
		return;
		break;
	}
}

void stmt(string &stream) {
	while (peek(stream) == BLANK) {
		advance(stream);
	}

	if (peek(stream) == ID) {
		match(stream, ID);
		match(stream, ASSIGN);
		val(stream);
	}
	else {
		err();
		return;
	}
}

void val(string &stream) {
	while (peek(stream) == BLANK) {
		advance(stream);
	}

	switch (peek(stream)) {
	case ID:
		match(stream, ID);
		break;
	case INUM:
		match(stream, INUM);
		break;
	default:
		err();
		return;
		break;
	}
}

int peek(string &stream) {
	if (stream.empty()) {
		return END;
	}
	else {
		char ch = stream.at(0);

		if (ch == '=') {
			return ASSIGN;
		}
		else if (ch == '.') {
			return ERR;
		}
		else if (isdigit(ch)) {
			return INUM;
		}
		else if (isalpha(ch)){
			return ID;
		}
		else if (ch == ' ') {
			return BLANK;
		}
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
		while (peek(stream) == BLANK) {
			advance(stream);
		}

		token ts;
		ts.type = type;
		ts.val = "";

		switch (type) {
		case ID:
			if (isalpha(stream.at(0))) {
				ts.val = advance(stream);
			}
			else {
				err();
				return;
			}
			break;
		case ASSIGN:
			if (stream.at(0) == '=') {
				ts.val = advance(stream);
			}
			else {
				err();
				return;
			}
			break;
		case INUM:
			char ch;
			while (!stream.empty() && isdigit(ch = advance(stream))) {
				ts.val.push_back(ch);
			}
			if (ch == '.') {
				err();
				return;
			}
			break;
		default:
			err();
			return;
			break;
		}

		list.push_back(ts);
	}
	else {
		err();
		return;
	}
}

void err() {
	cerr << "valid input";
	return;
	//exit(0);
}

void display() {
	token currentToken = list.at(0);

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
			return;
			break;
		}

		cout << currentToken.val << endl;
		list.erase(list.begin());

		if (!list.empty()) {
			currentToken = list.at(0);
		}
	}
}