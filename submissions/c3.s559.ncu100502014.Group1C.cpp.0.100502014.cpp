#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

int main() {
	string input, a, b;
	int i=0;
	bool isError=false;
	cin >> input;
	for(;i<input.length();i++) {
		if((input[i]-'a'>=0&&input[i]-'a'<26) || (input[i]-'A'>=0&&input[i]-'A'<26) || (input[i]-'_'==0)) {
			a+=input[i];
		}
		else if(input[i]-'('==0) {
			i++;
			break;
			
		}
		else {
			isError=true;
			break;
		}
	}
	if(!isError) {
		if(input[i]-'0'>=0&&input[i]-'0'<10) {
			b+=input[i];
			i++;
			for(;i<input.length();i++) {
				if(input[i]-'0'>=0&&input[i]-'0'<10) {
					b+=input[i];
				}
				else if(input[i]-')'==0) {
					break;
				}
				else {
					isError=true;
					break;
				}
			}
		}
		else if((input[i]-'a'>=0&&input[i]-'a'<26) || (input[i]-'A'>=0&&input[i]-'A'<26) || (input[i]-'_'==0)) {
			b+=input[i];
			i++;
			for(;i<input.length();i++) {
				if((input[i]-'a'>=0&&input[i]-'a'<26) || (input[i]-'A'>=0&&input[i]-'A'<26) || (input[i]-'_'==0)) {
					b+=input[i];
				}
				else if(input[i]-')'==0) {
					break;
				}
				else {
					isError=true;
					break;
				}
			}
		}
		else {
			isError=true;
		}

		if(!isError) {
			cout << "id " << a << endl;
			cout << "lparenthesis (" << endl;
			cout << "inum " << b << endl;
			cout << "rparenthesis )";
		}
		else {
			cout << "invalid input";
		}
	}
	else {
		cout << "invalid input";
	}
	system("pause");
	return 0;
}