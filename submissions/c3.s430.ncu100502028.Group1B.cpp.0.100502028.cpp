#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>

using namespace std;

int main () {
	string line;
	int outCount = 0;
	while (getline(cin, line) && outCount != 2){
		outCount++;
		istringstream in(line);
		string input[3];
		int count = 0;
		bool flag = true;

		while(in >> input[count])
			count++;
		if(flag == true) {
			if (count == 3) {
			if (input[0][0] == 'l' || input[0][0] == 'b') {
				int sizeOfFirstName = input[1].length();
				for (int i = 0; i < sizeOfFirstName - 1; i++){
					if ((input[1][i] >= 'a' && input[1][i] <= 'z') || (input[1][i] >= 'A' && input[1][i] <= 'Z')) {
						flag = true;
						int sizeOfLastName = input[2].length();

						for (int i = 0; i < sizeOfLastName - 1; i++){
							if ((input[2][i] >= 'a' && input[2][i] <= 'z') || (input[2][i] >= 'A' && input[2][i] <= 'Z')) {
								flag = true;
							}
							else {
								flag = false;
								cout << "invalid input" << endl;
							}
						}
					}
					else {
						flag = false;
						cout << "invalid input" << endl;
					} 
						
				}
				if (flag == true) {
					if (input[0][0] == 'l')
						cout << "level " << input[0] << endl;
					else
						cout << "battle " << input[0] << endl;
					cout << "FirstName " << input[1] << endl;
					cout << "LastName " << input[2] << endl;
				}
			}
			else {
				flag = false;
				cout << "invalid input" << endl;
			}
		}

		else if (count == 2) {
			if (input[0][0] == 'b') {
				int sizeOfID = input[1].length();
				for (int i = 0; i < sizeOfID - 1; i++){
					if ((input[1][i] >= '0' && input[1][i] <= '9')) {
						flag = true;
					}
					else {
						flag = false;
						cout << "invalid input" << endl;
					}
				}
				if (flag == true) {
					cout << "battle " << input[0] << endl;
					cout << "cid " << input[1] << endl;
				}
			}
			else {
				flag = false;
				cout << "invalid input" << endl;
			}
		}

		else {
								flag = false;
								cout << "invalid input" << endl;
							}
		}
		else
			cout << "invalid input" << endl;
		

		cout << endl;
	}
	system("pause");
	return 0;
}


















/*
	string line;
	while (getline(cin, line)){
		istringstream in(line);

		string input[3];
		int count = 0;
		bool flag = true;

		while(in >> input[count]) {
			count++;
		}

		for (int i = 0; i < count; i++)
			cout << input[i] << endl;
		cout << endl;

		if (count == 3){
			if (input[0] == "s") {
				if ((input[1] >= "a" && input[1] <= "o") || input[1] == "q" || input[1] == "r" || (input[1] >= "t" && input[1] <= "z")) {
					int sizeOfString = input[2].length();
					if (input[2][0] == '"' && input[2][sizeOfString-1] == '"') {
						char temp[100];
						for (int i = 1; i < sizeOfString-1; i++) {
							if ((input[2][i] >= 'a' && input[2][i] <= 'z') || (input[2][i] >= 'A' && input[2][i] <= 'Z') || (input[2][i] >= '0' && input[2][i] <= '9')) {
								temp[i-1] =  input[2][i];
							}
							else 
								flag = false;
						}
						if (flag == true) {
							cout << "strdcl " << input[0] << endl;
							cout << "id " << input[1] << endl;
							cout << "quote " << input[2][0] << endl;
							cout << "string ";
							for (int i = 0; i < sizeOfString-2; i++) {
								cout << temp[i];
							}
							cout << endl;
							cout << "quote " << input[2][sizeOfString-1] << endl;
						}
						else
							cout << "invalid input" << endl;
					}
					else 
						cout << "invalid input" << endl;
				}
				else
					cout << "invalid input" << endl;
			}
			else 
				cout << "invalid input" << endl;
		}

		else if (count == 2) {
			if (input[0] == "p") {
				if ((input[1] >= "a" && input[1] <= "o") || input[1] == "q" || input[1] == "r" || (input[1] >= "t" && input[1] <= "z")) {
					cout << "print " << input[0] << endl;
					cout << "id " << input[1] << endl;
				}
				else
					cout << "invalid input" << endl;
			}
			else 
				cout << "invalid input" << endl;
		}

		else 
			cout << "invalid input" << endl;

		cout << endl;
	}
	
	system("pause");
	return 0;
}
*/