#include <iostream>
#include <string>

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

	return 0;
}

void printInvalid() {
	cout << "valid input\n";
}

bool checkId(string id) {
	if ( id.length() != 1 ) return false;
	char charId = id[0];
	if ( charId == 'a' ) return true;
	if ( charId == 'b' ) return true;
	if ( charId == 'c' ) return true;
	if ( charId == 'd' ) return true;
	if ( charId == 'e' ) return true;
	if ( charId == 'f' ) return true;
	if ( charId == 'g' ) return true;
	if ( charId == 'h' ) return true;
	if ( charId == 'i' ) return true;
	if ( charId == 'j' ) return true;
	if ( charId == 'k' ) return true;
	if ( charId == 'l' ) return true;
	if ( charId == 'm' ) return true;
	if ( charId == 'n' ) return true;
	if ( charId == 'o' ) return true;
	if ( charId == 'p' ) return true;
	if ( charId == 'q' ) return true;
	if ( charId == 'r' ) return true;
	if ( charId == 's' ) return true;
	if ( charId == 't' ) return true;
	if ( charId == 'u' ) return true;
	if ( charId == 'v' ) return true;
	if ( charId == 'w' ) return true;
	if ( charId == 'x' ) return true;
	if ( charId == 'y' ) return true;
	if ( charId == 'z' ) return true;

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
				break;
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				break;
			case 8:
				break;
			case 9:
				break;
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
	int index = 0;

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