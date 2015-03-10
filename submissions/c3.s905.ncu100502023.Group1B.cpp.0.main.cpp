#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

bool checkLowerChar(char charId);
bool checkLowerCharNot_b(char charId);
bool checkUpperChar(char charId);

bool checkLevel(string);
bool checkFirstName(string);
bool checkLastName(string);

bool checkNumber(char);
bool checkCid(string);
bool checkBattle(string);
bool checkCidorName(char);

void printInvalid();
void printLevel(string);
void printFirstName(string);
void printLastName(string);
void printCid(string);
void printBattle();

bool cropper(string);

int main() {
	//string inputStream1;
	//string inputStream2;

	string inputStream;
	string tmp;

	while(getline(cin, tmp)) {
		inputStream.append(tmp);
		inputStream += " ";
	}

	cropper(inputStream);
	system("pause");
	return 0;
}

bool checkLowerChar(char charId) {
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

bool checkLowerCharNot_b(char charId) {
	if ( charId == 'a' ) return true;
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

bool checkUpperChar(char charId) {
	if ( charId == 'A' ) return true;
	if ( charId == 'B' ) return true;
	if ( charId == 'C' ) return true;
	if ( charId == 'D' ) return true;
	if ( charId == 'E' ) return true;
	if ( charId == 'F' ) return true;
	if ( charId == 'G' ) return true;
	if ( charId == 'H' ) return true;
	if ( charId == 'I' ) return true;
	if ( charId == 'J' ) return true;
	if ( charId == 'K' ) return true;
	if ( charId == 'L' ) return true;
	if ( charId == 'M' ) return true;
	if ( charId == 'N' ) return true;
	if ( charId == 'O' ) return true;
	if ( charId == 'P' ) return true;
	if ( charId == 'Q' ) return true;
	if ( charId == 'R' ) return true;
	if ( charId == 'S' ) return true;
	if ( charId == 'T' ) return true;
	if ( charId == 'U' ) return true;
	if ( charId == 'V' ) return true;
	if ( charId == 'W' ) return true;
	if ( charId == 'X' ) return true;
	if ( charId == 'Y' ) return true;
	if ( charId == 'Z' ) return true;

	return false;
}

bool checkLevel(string level) {
	bool flag = true;

	if ( level[0] != 'l' ) flag = false;

	for ( int index = 1 ; index < level.length() ; index++ ) {
		if ( ! flag ) break;
		if ( ! checkNumber(level[index]) ) flag = false;
	}

	return flag;
}

bool checkFirstName(string first) {
	bool flag = true;

	if ( ! checkUpperChar(first[0]) ) {
		flag = false;
	}

	for ( int index = 1 ; index < first.length() ; index++ ) {
		if ( ! flag ) {
			break;
		}
		if ( ! checkLowerChar(first[index]) ) {
			flag = false;
		}
	}

	return flag;
}

bool checkLastName(string last) {
	bool flag = true;
	
	for ( int i = 0 ; i < last.length() ; i++ ) {
		if ( ! checkLowerCharNot_b(last[i]) ) {
			flag = false;
		}
		if ( ! flag ) {
			break;
		}
	}

	return flag;
}

bool checkNumber(char input) {
	int digitChar = input - '0';

	if ( digitChar == 0 ) return true;
	if ( digitChar == 1 ) return true;
	if ( digitChar == 2 ) return true;
	if ( digitChar == 3 ) return true;
	if ( digitChar == 4 ) return true;
	if ( digitChar == 5 ) return true;
	if ( digitChar == 6 ) return true;
	if ( digitChar == 7 ) return true;
	if ( digitChar == 8 ) return true;
	if ( digitChar == 9 ) return true;

	return false;
}

bool checkCid(string cid) {
	bool flag = true;

	for ( int i = 0 ; i < cid.length() ; i++ ) {
		if ( ! flag ) {
			break;
		}
		if ( ! checkNumber(cid[i]) ) {
			flag = false;
		}
	}

	return flag;
}

bool checkBattle(string battle) {
	if ( battle[0] == 'b' ) {
		return true;
	} else {
		return false;
	}
}

bool checkCidorName(char input) {
	int digitInput = input - '0';

	if ( digitInput == 0 ) return true;
	if ( digitInput == 1 ) return true;
	if ( digitInput == 2 ) return true;
	if ( digitInput == 3 ) return true;
	if ( digitInput == 4 ) return true;
	if ( digitInput == 5 ) return true;
	if ( digitInput == 6 ) return true;
	if ( digitInput == 7 ) return true;
	if ( digitInput == 8 ) return true;
	if ( digitInput == 9 ) return true;

	return false;
}

void printInvalid() {
	cout << "invalid input\n";
}

void printLevel(string level) {
	cout << "level " << level << "\n";
}

void printFirstName(string first) {
	cout << "FirstName " << first << "\n";
}

void printLastName(string last) {
	cout << "LastName " << last << "\n";
}

void printCid(string cid) {
	cout << "cid " << cid << "\n";
}

void printBattle() {
	cout << "battle b\n";
}

bool cropper(string inputStream) {
	string level = "";
	string firstname1 = "";
	string lastname1 = "";
	string cid = "";
	string firstname2 = "";
	string lastname2 = "";

	string cid2 = "";

	string battle = "";

	bool flagLevel = false, flagFirstname = false, flagLastname = false, flagBattle = false, flagCidorName = false;
	bool doCid = false, doName = false;

	int index = 0;
	bool access = false;

	int id1 = 0;  // 0: cid 1: firstname
	int id2 = 0; // 0: cid 1: firstname

	bool flagCid1 = false;
	bool flagCid2 = false;
	bool flagName1 = false;
	bool flagName2 = false;
	bool flagCidorName2 = false;

	if ( ! flagLevel ) {
		for ( int i = index ; i < inputStream.length() ; i++ ) {
			if ( inputStream[i] == ' ' ) {
				index = i + 1;
				break;
			}
			level += inputStream[i];
			index = i + 1;
		}
	}

	if ( checkLevel(level) ) {
		flagLevel = true;
	} else {
		printInvalid();
		return 0;
	}

	if ( checkNumber(inputStream[index]) ) {
		id1 = 0; //cid
		for ( int i = index ; i < inputStream.length() ; i++ ) {
			if ( inputStream[i] == ' ' ) {
				index = i + 1;
				break;
			}
			cid += inputStream[i];
			index = i + 1;
		}

		if ( checkCid(cid) ) {
			flagCid1 = true;
		} else {
			printInvalid();
			return 0;
		}
	} else {
		id1 = 1;  //firstname lastname
		for ( int i = index ; i < inputStream.length() ; i++ ) {
			if ( inputStream[i] == ' ' ) {
				index = i + 1;
				break;
			}
			firstname1 += inputStream[i];
			index = i + 1;
		}

		if ( ! checkFirstName(firstname1) ) {
			printInvalid();
			return 0;
		}

		for ( int i = index ; i < inputStream.length() ; i++ ) {
			if ( inputStream[i] == ' ' ) {\
				index = i + 1;
				break;
			}
			lastname1 += inputStream[i];
			index = i + 1;
		}

		if ( checkLastName(lastname1) ) {
			flagName1 = true;
		} else {
			printInvalid();
			return 0;
		}
	}

	// stmt
	if ( ! flagBattle) {
		for ( int i = index ; i < inputStream.length() ; i++ ) {
			if ( inputStream[i] == ' ' ) {
				index = i + 1;
				break;
			}
			battle += inputStream[i];
			index = i + 1;
		}

		if ( checkBattle(battle) ) {
			flagBattle = true;
		} else {
			printInvalid();
			return 0;
		}
	}

	//id2
	if ( checkNumber(inputStream[index]) ) {
		id2 = 0; //cid
		for ( int i = index ; i < inputStream.length() ; i++ ) {
			if ( inputStream[i] == ' ' ) {
				index = i + 1;
				break;
			}
			cid2 += inputStream[i];
			index = i + 1;
		}

		if ( checkCid(cid2) ) {
			flagCid2 = true;
		} else {
			printInvalid();
			return 0;
		}
	} else {
		id2 = 1;  //firstname lastname
		for ( int i = index ; i < inputStream.length() ; i++ ) {
			if ( inputStream[i] == ' ' ) {
				index = i + 1;
				break;
			}
			firstname2 += inputStream[i];
			index = i + 1;
		}

		if ( ! checkFirstName(firstname2) ) {
			printInvalid();
			return 0;
		}

		for ( int i = index ; i < inputStream.length() ; i++ ) {
			if ( inputStream[i] == ' ' ) {
				index = i + 1;
				break;
			}
			lastname2 += inputStream[i];
			index = i + 1;
		}

		if ( checkLastName(lastname2) ) {
			flagName2 = true;
		} else {
			printInvalid();
			return 0;
		}
	}

	if ( flagLevel && (id1 == 0) && flagCid1 && flagBattle && (id2 == 0) && flagCid2 ) {
		printLevel(level);
		printCid(cid);
		printBattle();
		printCid(cid2);
	} else if ( flagLevel && (id1 == 1) && flagName1 && flagBattle && (id2 == 0) && flagCid2 ) {
		printLevel(level);
		printFirstName(firstname1);
		printLastName(lastname1);
		printBattle();
		printCid(cid2);
	} else if ( flagLevel && (id1 == 0) && flagCid1 && flagBattle && (id2 == 1) && flagName2 ) {
		printLevel(level);
		printCid(cid);
		printBattle();
		printFirstName(firstname2);
		printLastName(lastname2);
	} else if ( flagLevel && (id1 == 1) && flagName1 && flagBattle && (id2 == 1) && flagName2 ) {
		printLevel(level);
		printFirstName(firstname1);
		printLastName(lastname1);
		printBattle();
		printFirstName(firstname2);
		printLastName(lastname2);
	}

	/*
	int index1 = 0, index2 = 0;

	while ( index1 < inputStream1.length() ) {
		if ( ! flagLevel ) {
			if ( inputStream1[index1] ==  ' ' ) {
				flagLevel = true;
			} else {
				level += inputStream1[index1];
			}
		} else if ( ! flagFirstname ) {
			if ( inputStream1[index1] ==  ' ' ) {
				flagFirstname = true;
			} else {
				firstname1 += inputStream1[index1];
			}
		} else if ( ! flagLastname ) {
			if ( inputStream1[index1] ==  ' ' ) {
				flagLastname = true;
			} else {
				lastname1 += inputStream1[index1];
			}
		}
		++index1;
	}
	// init
	flagFirstname = false;
	flagLastname = false;

	while ( index2 < inputStream2.length() ) {
		if ( ! flagBattle ) {
			if ( inputStream2[index2] ==  ' ' ) {
				flagBattle = true;
			} else {
				battle += inputStream2[index2];
			}
		} else if ( ! flagCidorName ) {
			if ( ! doCid && ! doName ) {
				if ( checkCidorName(inputStream2[index2]) ) {
					doCid = true;
				} else {
				    doName = true;
				}
			}

			if ( doCid ) {
				cid += inputStream2[index2];
			} else {
				if ( ! flagFirstname ) {
					if ( inputStream2[index2] ==  ' ' ) {
						flagFirstname = true;
					} else {
						firstname2 += inputStream2[index2];
					}
				} else if ( ! flagLastname ) {
					if ( inputStream2[index2] ==  ' ' ) {
						flagLastname = true;
					} else {
						lastname2 += inputStream2[index2];
					}
				}
			}
		}

		++index2;
	}

	bool access = true;

	if ( ! checkLevel(level) ||  ! checkFirstName(firstname1) || ! checkLastName(lastname1) ) {
		printInvalid();
		access = false;
	} else {
		printLevel(level);
		printFirstName(firstname1);
		printLastName(lastname1);
	}

	if ( access ) {
		if ( doCid ) {
			if ( ! checkBattle(battle) || ! checkCid(cid) ) {
				printInvalid();
			} else {
				printBattle();
				printCid(cid);
			}
		} else {
			if ( ! checkFirstName(firstname2) || ! checkLastName(lastname2) ) {
				printInvalid();
			} else {
				printBattle();
				printFirstName(firstname2);
				printLastName(lastname2);
			}
		}
	}

	*/
}