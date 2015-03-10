#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

struct token{
	string type;
	string val;
};

int main()
{
    string input, input1, input2;
	/*while (getline(cin, input1)){
		for (int i = 0; i < input1.length(); i++){
			input += input1[i];
		}
	input += ' ';
	}*/
	getline(cin, input1);
	input += input1 + " ";
	getline(cin, input2);
	input += input2 + " ";
	//cout << input << endl;
	
	bool flag = true;
	token tokens[50];
	int index = 0;
	for (int i = 0; i < input.length(); i++){
		if (input[i] == ' ' || input[i] == '$')
			continue;
		else if (input[i] == 's'){
			token ans;
            ans.type = "strdcl";
            ans.val = "s";
            tokens[index] = ans;
			index++;
			continue;
		}
		else if (input[i] == 'p'){
			token ans;
            ans.type = "print";
            ans.val = "p";
            tokens[index] = ans;
			index++;
			continue;
		}
		else if (input[i] == '\"'){
            token ans;
            ans.type = "quote";
            ans.val = "\"";
            tokens[index] = ans;
			index++;
			continue;
        }
		else if (input[i-1] == '\"'){
			token ans;
            ans.type = "string";
			while (input[i] != '\"'){
				if ( (input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= '0' && input[i] <= '9') ){
					ans.val += input[i];
					i++;
				}
				else {
					flag = false;
					i = input.length();
					break;
				}
			}
			i--;
            tokens[index] = ans;
			index++;
			continue;
		}
		else if (input[i] >= 'a' && input[i] <= 'z' && input[i] != 'q' && input[i] != 's'){
			token ans;
            ans.type = "id";
			while (input[i] != '\"' && input[i] != ' '){
				if (input[i] >= 'a' && input[i] <= 'z' && input[i] != 'q' && input[i] != 's'){
					ans.val += input[i];
					i++;
				}
				else {
					flag = false;
					i = input.length();
					break;
				}
			}
			i--;
            tokens[index] = ans;
			index++;
			continue;
		}
		else {
			flag = false;
			break;
		}
	}

	if (flag==true) {
        for(int i = 0; i < index; i++)
            cout << tokens[i].type << " " << tokens[i].val << endl;
	}
	else cout << "invalid input" << endl;
	
    system("pause");
	return 0;
}
