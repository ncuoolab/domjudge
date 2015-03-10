#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>

using namespace std;

int main () {
	string line = "";
	int outCount = 0;
	bool flag = true;
	string temp = "";

	getline(cin, line) ;
		istringstream in(line);
		string input[6];
		
		int count = 0;

		while(in >> input[count])
			count++;

		if (count == 6) {
			if (input[0][0] == 'l') {
				int sizeOfFirstName = input[1].length();
				for (int i = 1; i < sizeOfFirstName - 1; i++){
					if ((input[1][i] >= 'a' && input[1][i] <= 'z') && (input[1][0] >= 'A' && input[1][0] <= 'Z')) {
						flag = true;
						int sizeOfLastName = input[2].length();

						for (int i = 0; i < sizeOfLastName - 1; i++){
							if ((input[2][i] == 'a'|| (input[2][i] >= 'c' && input[2][i] <= 'z'))) {
								flag = true;
							}
							else {
								flag = false;
							}
						}
					}
					else {
						flag = false;
					} 
				}
				if (flag == true) {
					temp += "level " + input[0] + "\n";
					temp += "FirstName " + input[1] + "\n";
					temp += "LastName " + input[2] + "\n";
				}
			}

			else {
				flag = false;
			}

			if (input[3][0] == 'b') {
				int sizeOfFirstName = input[1].length();
				for (int i = 1; i < sizeOfFirstName - 1; i++){
					if ((input[4][i] >= 'a' && input[4][i] <= 'z') && (input[4][0] >= 'A' && input[4][0] <= 'Z')) {
						flag = true;
						int sizeOfLastName = input[2].length();

						for (int i = 0; i < sizeOfLastName - 1; i++){
							if ((input[5][i] == 'a'|| (input[5][i] >= 'c' && input[5][i] <= 'z'))) {
								flag = true;
							}
							else {
								flag = false;
							}
						}
					}
					else {
						flag = false;
					} 
				}
				if (flag == true) {
					temp += "battle " + input[3] + "\n";
					temp += "FirstName " + input[4] + "\n";
					temp += "LastName " + input[5] + "\n";
				}
			}

			else {
				flag = false;
			}
		}

		else if (count == 5) {
			if (input[0][0] == 'l') {
				int sizeOfFirstName = input[1].length();
				for (int i = 1; i < sizeOfFirstName - 1; i++){
					if ((input[1][i] >= 'a' && input[1][i] <= 'z') && (input[1][0] >= 'A' && input[1][0] <= 'Z')) {
						flag = true;
						int sizeOfLastName = input[2].length();

						for (int i = 0; i < sizeOfLastName - 1; i++){
							if ((input[2][i] == 'a'|| (input[2][i] >= 'c' && input[2][i] <= 'z'))) {
								flag = true;
							}
							else {
								flag = false;
							}
						}
					}
					else {
						flag = false;
					} 
				}
				if (flag == true) {
					temp += "level " + input[0] + "\n";
					temp += "FirstName " + input[1] + "\n";
					temp += "LastName " + input[2] + "\n";
				}
			}

			else {
				flag = false;
			}

			if (input[3][0] == 'b') {
				int sizeOfID = input[1].length();
				for (int i = 0; i < sizeOfID - 1; i++){
					if ((input[4][i] >= '0' && input[4][i] <= '9')) {
						flag = true;
					}
					else {
						flag = false;
					}
				}
				if (flag == true) {
					temp +=  "battle " + input[0] + "\n";
					temp += "cid " + input[1] + "\n";
				}
			}
			else {
				flag = false;
			}
		}

		else {
			flag = false;
		}
		
	

	if(flag == true) {
		cout << temp;
	}
	else
		cout << "invalid input" << endl;
	
	system("pause");
	return 0;
}