#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

bool checkId(string);
bool checkAssign(string);
bool checkInum(string);

void printInvalid();
void printID(string);
void printAssign();
void printInum(string);

void cropper(string);

int main() {
	string inputStream;

	while (true) {
		getline(cin, inputStream);
		cropper(inputStream);
	}

	system("pause");
	return 0;
}

void printInvalid() {
	cout << "valid input\n";
}

bool checkId(string id) {
	if ( id == "a" ) return true;
	if ( id == "b" ) return true;
	if ( id == "c" ) return true;
	if ( id == "d" ) return true;
	if ( id == "e" ) return true;
	if ( id == "f" ) return true;
	if ( id == "g" ) return true;
	if ( id == "h" ) return true;
	if ( id == "i" ) return true;
	if ( id == "j" ) return true;
	if ( id == "k" ) return true;
	if ( id == "l" ) return true;
	if ( id == "m" ) return true;
	if ( id == "n" ) return true;
	if ( id == "o" ) return true;
	if ( id == "p" ) return true;
	if ( id == "q" ) return true;
	if ( id == "r" ) return true;
	if ( id == "s" ) return true;
	if ( id == "t" ) return true;
	if ( id == "u" ) return true;
	if ( id == "v" ) return true;
	if ( id == "w" ) return true;
	if ( id == "x" ) return true;
	if ( id == "y" ) return true;
	if ( id == "z" ) return true;

	return false;
}
bool checkAssign(string assign) {
	if ( assign == "=" ) return true;
	return false;
}
bool checkInum(string stringNum) {
	int num;
	bool flag = true;
	for(int i = 0 ; i < stringNum.length() ; i++ ) {
		num = stringNum[i] - '0';
		switch( num ) {
			case 0:
				continue;
			case 1:
				continue;
			case 2:
				continue;
			case 3:
				continue;
			case 4:
				continue;
			case 5:
				continue;
			case 6:
				continue;
			case 7:
				continue;
			case 8:
				continue;
			case 9:
				continue;
			default:
				flag = false;
		}

		if ( ! flag ) break;
	}

	return flag;
}

void printID(string id) {
	cout << "id " << id << "\n";
}
void printAssign() {
	cout << "assign =\n";
}
void printInum(string inum) {
	cout << "inum " << inum << "\n";
}

void cropper(string inputStream) {
	string id = "";
	string assign = "";
	string Inum = "";
	bool flagID = false, flagAssign = false, flagInum = false;
	int index = 0, j = 0, k = 0;

	while ( index < inputStream.length() ) {
		if ( ! flagID ) {
			if ( inputStream[index] ==  ' ' ) {
				flagID = true;
			} else {
				id += inputStream[index];
			}
		} else if ( ! flagAssign ) {
			if ( inputStream[index] ==  ' ' ) {
				flagAssign = true;
			} else {
				assign += inputStream[index];
			}
		} else if ( ! flagInum ) {
			if ( inputStream[index] ==  ' ' ) {
				flagInum = true;
			} else {
				Inum += inputStream[index];
			}
		}
		++index;
	}
	if ( ! checkId(id) || ! checkAssign(assign) || ! checkInum(Inum) ) {
		printInvalid();
	} else {
		printID(id);
		printAssign();
		printInum(Inum);
	}
}