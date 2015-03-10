#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

enum type { ERR, LEVEL, FIRSTNAME, LASTNAME, CID, BATTLE, BLANK, END };

void proc(string&);
void stmt(string&);
int peek(string&);
char advance(string&);
void dcl(string&);
void id(string&);
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
	//system("pause"); //Should be deleted*********************************************************
	return 0;
}

void proc(string &stream) {
	while (peek(stream) == BLANK) {
		advance(stream);
	}

	switch (peek(stream)) {
	case LEVEL:
		dcl(stream);
		stmt(stream);
		break;
	default:
		err();
		break;
	}
}

void dcl(string &stream) {
	while (peek(stream) == BLANK) {
		advance(stream);
	}

	match(stream, LEVEL);
	id(stream);
}

void id(string &stream) {
	while (peek(stream) == BLANK) {
		advance(stream);
	}

	if(peek(stream) == CID) {
		match(stream, CID);
	}
	else if(peek(stream) == FIRSTNAME) {
		match(stream, FIRSTNAME);

		while (peek(stream) == BLANK) {
			advance(stream);
		}

		if(peek(stream) == LASTNAME) {
			match(stream, LASTNAME);
		}
		else {
			err();
		}
	}
	else {
		err();
	}
}

void stmt(string &stream) {
	if(!stream.empty()) {
		while (peek(stream) == BLANK) {
		advance(stream);
		}
		
		if (peek(stream) == BATTLE) {
			match(stream, BATTLE);
			id(stream);
		}
		else {
			err();
		}
	}
	else {
		err();
	}
}

int peek(string &stream) {
	if (stream.empty()) {
		return END;
	}
	else {
		char ch = stream.at(0);

		if (ch == 'l') {
			if(isdigit(stream.at(1))) {
				return LEVEL;
			}
		}
		else if (ch == 'b') {
			return BATTLE;
		}
		else if (islower(ch) && ch != 'b') {
			return LASTNAME;
		}
		else if (isdigit(ch)) {
			return CID;
		}
		else if (isupper(ch) && islower(stream.at(1))){
			return FIRSTNAME;
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
		case LEVEL:
			if (stream.at(0) == 'l') {
				ts.val.push_back(advance(stream));

				while (!stream.empty() && isdigit(stream.at(0))) {
					ts.val.push_back(advance(stream));
				}

				if(!stream.empty() && isalpha(stream.at(0))) {
					err();
				}
			}
			else {
				err();
			}
			break;
		case FIRSTNAME:
			if(isupper(stream.at(0))) {
				ts.val.push_back(advance(stream));

				while(!stream.empty() && islower(stream.at(0))) {
					ts.val.push_back(advance(stream));
				}

				if(!stream.empty() && isdigit(stream.at(0))) {
					err();
				}
			}
			else {
				err();
			}
			break;
		case LASTNAME:
			while(!stream.empty() && islower(stream.at(0)) && stream.at(0) != 'b') {
				ts.val.push_back(advance(stream));
			}

			if(!stream.empty() && (stream.at(0) == 'b' || isdigit(stream.at(0)))) {
				err();
			}
			break;
		case CID:
			while (!stream.empty() && isdigit(stream.at(0))) {
				ts.val.push_back(advance(stream));
			}
			if (!stream.empty() && stream.at(0) == '.') {
				err();
			}
			break;
		case BATTLE:
			if(stream.at(0) == 'b') {
				ts.val.push_back(advance(stream));

				if(!stream.empty() && isdigit(stream.at(0)) && isalpha(stream.at(0))) {
					err();
				}
			}
			else {
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

void display() {
	token currentToken = list.at(0);

	while (!list.empty()) {
		switch (currentToken.type) {
		case LEVEL:
			cout << "level ";
			break;
		case FIRSTNAME:
			cout << "FirstName ";
			break;
		case LASTNAME:
			cout << "LastName ";
			break;
		case CID:
			cout << "cid ";
			break;
		case BATTLE:
			cout << "battle ";
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