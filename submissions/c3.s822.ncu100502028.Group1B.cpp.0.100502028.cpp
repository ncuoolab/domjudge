#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>

using namespace std;

int main () {
	string line = "";
	int outCount = 0;
	bool flag[2] = {true, true};
	string temp[2] = {};

	while (true) {
		getline(cin, line);
		istringstream in(line);
		string input[3];
		int count = 0;

		while(in >> input[count])
			count++;

		if (count == 3) {
			if (input[0][0] == 'l' || input[0][0] == 'b') {
				int sizeOfFirstName = input[1].length();
				for (int i = 1; i < sizeOfFirstName - 1; i++){
					if ((input[1][i] >= 'a' && input[1][i] <= 'z') && (input[1][0] >= 'A' && input[1][0] <= 'Z')) {
						flag[outCount] = true;
						int sizeOfLastName = input[2].length();

						for (int i = 0; i < sizeOfLastName - 1; i++){
							if ((input[2][i] == 'a'|| (input[2][i] >= 'c' && input[2][i] <= 'z'))) {
								flag[outCount] = true;
							}
							else {
								flag[outCount] = false;
							}
						}
					}
					else {
						flag[outCount] = false;
					} 
				}
				if (flag[outCount] == true) {
					if (input[0][0] == 'l')
						temp[outCount] += "level " + input[0] + "\n";
					else
						temp[outCount] += "battle " + input[0] + "\n";
					temp[outCount] += "FirstName " + input[1] + "\n";
					temp[outCount] += "LastName " + input[2] + "\n";
				}
			}
			else {
				flag[outCount] = false;
			}
		}

		else if (count == 2) {
			if (input[0][0] == 'b') {
				int sizeOfID = input[1].length();
				for (int i = 0; i < sizeOfID - 1; i++){
					if ((input[1][i] >= '0' && input[1][i] <= '9')) {
						flag[outCount] = true;
					}
					else {
						flag[outCount] = false;
					}
				}
				if (flag[outCount] == true) {
					temp[outCount] +=  "battle " + input[0] + "\n";
					temp[outCount] += "cid " + input[1] + "\n";
				}
			}
			else {
				flag[outCount] = false;
			}
		}

		else {
			flag[outCount] = false;
		}
		outCount++;
	}

	if(flag[0] == true && flag[1] == true) {
			cout << temp[0];
			cout << temp[1];
	}
	else
		cout << "invalid input" << endl;
	
	system("pause");
	return 0;
}