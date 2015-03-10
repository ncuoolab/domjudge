#include <iostream>
#include <string>
//#include <stdlib.h>

using namespace std;

struct token{
	string type;
	string val;
};

int main()
{
    string input;
    //cin >> input;
	getline (cin,input);
	//cout << input << endl;
	input = input + '$';
	token tokens[100];
	int index = 0;
	int current = 0;
	bool flag = false;

	while (input[current] != '$'){
		if ( (input[current]>='0'&&input[current]<='9') ||
			 (input[current]>='a'&&input[current]<='z') ||
			 (input[current]>='A'&&input[current]<='Z') ||
			 (input[current] == '\"') || input[current] == ' ') {
			flag = true;
			current++;
		}
		else {
			flag = false;
			break;
		}
	}

	current=0;
	if (flag==true) {
        while (input[current] != '$'){
            if (input[current] == 's'){
                token ans;
                ans.type = "strdcl";
                ans.val = "s";
                current++;
                tokens[index] = ans; index++;
            }
            else if (input[current] == ' '){
                current++;
            }
            else if (input[current] == '\"'){
                token ans;
                ans.type = "quote";
                ans.val = "\"";
                current++;
                tokens[index] = ans; index++;
            }
            else if (input[current] == 'p'){
                token ans;
                ans.type = "print";
                ans.val = "p";
                current++;
                tokens[index] = ans; index++;
            }
            else {
                if (input[current-1] == '\"'){
                    token ans;
                    ans.type = "string";
                    while (input[current]!='\"'){
                        ans.val += input[current];
                        current++;
                    }
                    tokens[index] = ans; index++;
                }
                else {
                    token ans;
                    if ( (input[current] >= 'a' && input[current] <= 'o') || (input[current] >= 'q' && input[current] <= 'r') || (input[current] >= 't' && input[current] <= 'z') ){
                        ans.type = "id";
                        while (input[current]!=' '){
                            ans.val += input[current];
                            current++;
                        }
                        tokens[index] = ans; index++;
                    }
                    else {
                        flag = false;
                    }
                }
            }
            if (flag==false)
                break;
        } // end while
	} // end if flag is true

	if (flag==true) {
        for(int i = 0; i < index; i++){
            cout << tokens[i].type << " " << tokens[i].val << endl;
        }
	}
	else cout << "invalid input" << endl;

    //system("pause");
	return 0;
}
