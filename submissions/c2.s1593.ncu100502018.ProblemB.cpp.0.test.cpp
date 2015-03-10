#include <iostream>
#include <string>
using namespace std;
string tokens[5] = {"strdcl", "id", "quote", "string", "print"};
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
	string correct = "";
	for(int i = 0; i < input.length(); i++) {
		if(input[i] != ' ') {
			if(correct == "") {
				if(input[i] != 's') {
					Error();
					return 0;
				}
				else {
					output += " " + tokens[0];
					sinput = sinput + input[i] + " ";
					correct = tokens[0];
				}
			}
			else if(correct == tokens[0] || correct == tokens[4]) {
				if(input[i] < 97 || input[i] > 122 || input[i] == 70 || input[i] == 115) {
					Error();
					return 0;
				}
				else {
					output += " " + tokens[1];
					sinput = sinput + input[i] + " ";
					correct = tokens[1];
				}
			}
			else if(correct == tokens[1] || correct == tokens[3]) {
				if(input[i] != '"') {
					Error();
					return 0;
				}
				else {
					output += " " + tokens[2];
					sinput = sinput + input[i] + " ";
					correct = tokens[2];
				}
			}
			else if(correct == tokens[2]) {
				if(input[i] == 'p') {
					output += " " + tokens[4];
					sinput = sinput + input[i] + " ";
					correct = tokens[4];
				}
				else {
					while(input[i] != '"')
						temp += input[i++];
					for(int j = 0; j < temp.length(); j++) {
						if((temp[j] >= 48 && temp[j] <= 57) || (temp[j] >= 65 && temp[j] <= 90) || (temp[j] >= 97 && temp[j] <= 122)) {
						}
						else {
							Error();
							return 0;
						}
					}
					output += " " + tokens[3];
					sinput = sinput + temp + " ";
					correct = tokens[3];
					i--;
				}
			}
			else {
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