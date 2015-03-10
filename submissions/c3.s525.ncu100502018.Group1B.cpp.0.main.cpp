#include <iostream>
#include <string>
using namespace std;
void Error();
string tokens[5] = {"level", "cid", "FirstName", "LastName", "battle"};
int correct = 0;

int main() {
	string input;
	getline(cin, input);
	string temp = "";
	string sinput = "";
	string output = "";
	input += " ";
	for(int i=0;i < input.length(); i++) {
		if(input[i] == 'l') {
			temp += 'l';
			while(input[++i] != ' ') {
				if(input[i] <= 57 && input[i] >= 48)
					temp += input[i];
				else {
					Error();
					return 0;
				}
			}
			sinput += temp;
			output += tokens[0];
			temp = "";
		}
		else if(input[i] >= 65 && input[i] <= 90) {
			temp += input[i];
			while(input[++i] != ' ')
				temp += input[i];
			for(int j =1;j < temp.length();j++) {
				if(temp[j] < 97 || temp[j] > 122) {
					Error();
					return 0;
				}
			}
			sinput += " " + temp;
			output += " " + tokens[2];
			temp = "";
		}
		else if(input[i] == 97 || (input[i] > 98 && input[i] < 122)) {
			temp += input[i];
			while(input[++i] != ' ')
				temp += input[i];
			for(int j=1;j < temp.length();j++) {
				if(input[i] > 98 && input[i] < 122) {
					Error();
					return 0;
				}
			}
			sinput += " " + temp;
			output += " " + tokens[3];
			temp = "";
		}
		else if(input[i] >= 48 && input[i] <= 57) {
			temp += input[i];
			while(input[++i] != ' ')
				temp += input[i];
			for(int j=1;j < temp.length();j++) {
				if(temp[j] < 48||temp[j]>57) {
					Error();
					return 0;
				}
			}
			sinput += " " + temp;
			output += " " + tokens[1];
			temp = "";
		}
		else if(input[i] == 'b') {
			temp = 'b';		
			if(temp.length() > 1) {
				Error();
				return 0;
			}
			sinput += " " + temp;
			output += " " + tokens[4];
			temp = "";
		}
	}
	sinput += " ";
	output += " ";
	int order = 0;
	int flag = 0;
	for(int i = 0; i< output.length(); i++) {
		if(output[i] != ' ')
			cout << output[i];
		else {
			order= 0;
			cout << " ";			
			if(flag == 0) {
				cout << sinput[order];
				flag--;
			}
			while(sinput[++order] != ' ') {
				cout << sinput[order];
			}
			sinput = sinput.substr(order, sinput.length() - order);
			cout << endl;
		}
	}
	return 0;
}

void Error() {
	cout << "invalid input" << endl;
}

int Correct() {
	return (correct++) % 6;
}