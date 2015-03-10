#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
	string input;
	string token[1000];
	string alph = "abcdefghijklmnopqrstuvwxyz";
	string Alph = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string nums = "0123456789";
	cin  >> input;
	input += "/";
	int i = 0;
    while(input[i] != '/') {
        for(int j=0; j<26; j++) {
            if(input[i] == alph[j] || input[i] == Alph[j]) {
                token[i] = "id";
                break;
            }
        }
        for(int j=0; j<9; j++) {
            if(input[i] == alph[j]) {
                token[i] = "inum";
                break;
            }
        }
        if(input[i] == '(') {
            token[i] == "lparenthesis";

        }else if(input== '(') {
            token[i] == "rparenthesis";
        }else {
            cout << "invalid input";
            break;
        }
        i++;
    }


	system("pause");
	return 0;
}
