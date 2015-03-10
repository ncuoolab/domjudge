#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

int main() {
	string input, a, b;
	int i=0, type;
	bool isError=false;
	getline(cin, input);
	for(;i<input.length();i++) {
		if(input[i]-' '!=0) {
			break;
		}
	}
	if((input[i]-'a'>=0&&input[i]-'a'<26) || (input[i]-'A'>=0&&input[i]-'A'<26) || (input[i]-'_'==0)) {
		a+=input[i];
		i++;
		for(;i<input.length();i++) {
			if(input[i]-' '==0 && input[i+1]-'('==0) {
				i+=2;
				break;
			}
			if((input[i]-'a'>=0&&input[i]-'a'<26) || (input[i]-'A'>=0&&input[i]-'A'<26) || (input[i]-'_'==0)) {
				a+=input[i];
			}
			else if(input[i]-'('==0) {
				i++;
				break;
			}
			else {
				//cout << "1";
				isError=true;
				break;
			}
		}
	}
	else {
		isError = true;
	}
	
	
	if(!isError && i!=input.length()) {
		for(;i<input.length();i++) {
			if(input[i]-' '!=0) {
				break;
			}
		}
		if(input[i]-'0'>=0&&input[i]-'0'<10) {
			type = 1;
			b+=input[i];
			i++;
			if(i!=input.length()) {
				for(;i<input.length();i++) {
					if(input[i]-'0'>=0&&input[i]-'0'<10) {
						b+=input[i];
					}
					else if(input[i]-')'==0 || (input[i]-' '==0 && input[i+1]-')'==0)) {
						i++;
						break;
					}
					else {
						//cout << "2";
						isError=true;
						break;
					}
				}
			}
			else {
				//cout << "3";
				isError = true;
			}
		}
		else if((input[i]-'a'>=0&&input[i]-'a'<26) || (input[i]-'A'>=0&&input[i]-'A'<26) || (input[i]-'_'==0)) {
			type = 2;
			b+=input[i];
			i++;
			if(i!=input.length()) {
				for(;i<input.length();i++) {
					if((input[i]-'a'>=0&&input[i]-'a'<26) || (input[i]-'A'>=0&&input[i]-'A'<26) || (input[i]-'_'==0)) {
						b+=input[i];
					}
					else if(input[i]-')'==0 || (input[i]-' '==0 && input[i+1]-')'==0)) {
						i++;
						break;
					}
					else {
						//cout << "4";
						isError=true;
						break;
					}
				}
			}
			else {
				//cout << "5";
				isError = true;
			}
		}
		else if(input[i]-')'==0){
			type = 3;		
		}
		else {
			//cout << "6";
			isError = true;
		}

		if(!isError) {
			cout << "id " << a << endl;
			cout << "lparenthesis (" << endl;
			if(type==1) {
				cout << "inum " << b << endl;
			}
			else if(type==2) {
				cout << "id " << b << endl;
			}
			else {
				cout << "£f" << endl;
			}
			cout << "rparenthesis )";
		}
		else {
			cout << "invalid input";
		}
	}
	else {
		cout << "invalid input";
	}
	cout << endl;
	system("pause");
	return 0;
}