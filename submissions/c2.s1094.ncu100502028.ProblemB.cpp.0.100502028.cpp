#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	string result1 = "", result2 = "";
	int correct1 = 0, correct2 = 0;
	string line;
	string temp_id = "";
	while (getline(cin, line)){
		istringstream in(line);

		string input[2];
		int count = 0;
		bool flag = true;

		while(in >> input[count]) {
			count++;
		}

		/*for (int i = 0; i < count; i++)
			cout << input[i] << endl;
		cout << endl;*/

		if (count == 2){
			if (input[0] == "s") {
				char temp[100];
				int sizeOfString = input[1].length();
				if ((input[1][0] >= 'a' && input[1][0] <= 'o') || input[1][0] == 'q' || input[1][0] == 'r' || (input[1][0] >= 't' && input[1][0] <= 'z') && input[1][1] == '"' && input[1][sizeOfString-1] == '"') {
					temp_id += input[1][0];
					for (int i = 2; i < sizeOfString - 1; i++) {
						if ((input[1][i] >= 'a' && input[1][i] <= 'z') || (input[1][i] >= 'A' && input[1][i] <= 'Z') || (input[1][i] >= '0' && input[1][i] <= '9') || input[1][i] == ' ') {
							temp[i-2] =  input[1][i];
						}
						else
							flag = false;
					}
				}
				else
					flag = false;

				if (flag == true) {
					result1 += "strdcl " + input[0] + "\n";
					result1 += "id " ;
					result1 += input[1][0];
					result1 += "\n";
					result1 += "quote ";
					result1 += input[1][1];
					result1 += "\n";
					for (int i = 2; i < sizeOfString - 1; i++) {
					if((input[1][i] != ' ')) {
                        result1 += "string ";
                        for (int i = 0; i < sizeOfString - 3; i++) {
                            result1 += temp[i];
                        }
					}
					}
					result1 += "\n";
					result1 += "quote ";
					result1 += input[1][sizeOfString-1];
					result1 += "\n";

					correct1++;

					/*cout << "strdcl " << input[0] << endl;
					cout << "id " << input[1][0] << endl;
					cout << "quote " << input[1][1] << endl;
					cout << "string ";
					for (int i = 0; i < sizeOfString - 2; i++) {
						cout << temp[i];
					}
					cout << endl;
					cout << "quote " << input[1][sizeOfString-1] << endl;*/
				}
			}


			else if (input[0] == "p") {
				if ((input[1][0] >= 'a' && input[1][0] <= 'o') || input[1][0] == 'q' || input[1][0] == 'r' || (input[1][0] >= 't' && input[1][0] <= 'z')) {
                    if(input[1] == temp_id)
                        flag = true;
                    else
                        flag = false;
				}
				else
					flag = false;

				if (flag == true) {
					result2 += "print " + input[0] + "\n";
					result2 += "id " + input[1];

					correct2++;
					/*cout << "print " << input[0] << endl;
					cout << "id " << input[1];*/
				}
			}
			else
				flag = false;
		}

		/*else
			cout << "valid input" << endl;*/
	}

	if (correct1 + correct2 == 2)
		cout << result1 << result2;
	else
		cout << "valid input" << endl;

	system("pause");
	return 0;
}
