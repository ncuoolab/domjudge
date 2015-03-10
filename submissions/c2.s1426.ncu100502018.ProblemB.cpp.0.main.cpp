#include <iostream>
#include <string>
using namespace std;
string tokens[5] = {"strdcl", "id", "quote", "string", "print"};
string standard[7] = {"strdcl", "id", "quote", "string", "quote", "print", "id"};
void Error();

int main() {
	string input;
	string inputtemp;
	while(getline(cin, inputtemp))
		input += " " + inputtemp;
	string temp = "";
	string output = "";
	int order = 0;
	input += " ";
	input = input.substr( 1, input.length() - 1);
	string sinput = "";
	for(int i = 0; i < input.length(); i++) {
		if(input[i] != ' ')
			temp += input[i];
		else {
			if(temp.length() == 1) {
				if(temp[0] == 's') {
					if(tokens[0] != standard[(order++)%7]) {
						Error();
						return 0;
					}
					else {
						output += " " + tokens[0];
						sinput += temp + " ";
					temp = "";
					}
				}
				else if(temp[0] == 'p') {
						if(tokens[4] != standard[(order++)%7]) {
						Error();
						return 0;
				}
					else {
						output += " " + tokens[4];
						sinput += temp + " ";
						temp = "";
					}
				}
				else if(temp[0] >= 97 && temp[0] <= 122) {
					if(tokens[1] != standard[(order++)%7]) {
						Error();
						return 0;
					}
					else {
						output += " " + tokens[1];
						sinput += temp + " ";
						temp = "";
					}
				}
				else {
					Error();
				return 0;
				}
			}
			else if(temp.length() > 1) {
				if(temp[0] != '"' || temp[temp.length() - 1] != '"') {
					Error();
					return 0;
				}
				else {
					for(int j = 1; j < temp.length() - 1; j++) {
						if(temp[j] < 48 || (temp[j] > 57 && temp[j] < 65) || (temp[j] > 90 && temp[j] < 97) || temp[j] > 122) {
							Error();
							return 0;
						}
					}
					output += " " + tokens[2] + " " + tokens[3] + " " + tokens[2];
					sinput = sinput + temp[0] + " " + temp.substr(1, temp.length() - 2) + " " + temp[temp.length() - 1] + " ";
					temp = "";
					order += 3;
				}
			}
			else {
				Error();
				return 0;
			}
		}
	}
	output = output.substr(1, output.length() - 1) + " ";
	for(int i = 0; i < output.length(); i++) {
		if(output[i] != ' ')
			cout << output[i];
		else {
			cout << " ";
			int now = 0;
			while(now < sinput.length()) {
				if(sinput[now] != ' ') {
					cout << sinput[now++];
				}
				else {
					int change = now + 1;
					sinput = sinput.substr(change, sinput.length() - change);
					now = sinput.length();
				}
			}
			cout << endl;
		}
	}
	return 0;
}

void Error() {
	cout << "valid input" << endl;
}
