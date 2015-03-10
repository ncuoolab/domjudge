#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>

using namespace std;

int main()
{	
	string line;
	while (getline(cin, line)){
		istringstream in(line);

		string input[5];
		int count = 0;
		bool flag = true;

		while(in >> input[count]) {
			count++;
		}

		/*for (int i = 0; i < count; i++)
			cout << input[i] << endl;
		cout << endl;*/

		if (count == 5){
			if (input[0] == "s") {
				if ((input[1][0] >= 'a' && input[1][0] <= 'o') || input[1][0] == 'q' || input[1][0] == 'r' || (input[1][0] >= 't' && input[1][0] <= 'z')) {
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
			if (input[3] == "p") {
				if ((input[4][0] >= 'a' && input[4][0] <= 'o') || input[4][0] == 'q' || input[4][0] == 'r' || (input[4][0] >= 't' && input[4][0] <= 'z')) {
					cout << "print " << input[3] << endl;
					cout << "id " << input[4] << endl;
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