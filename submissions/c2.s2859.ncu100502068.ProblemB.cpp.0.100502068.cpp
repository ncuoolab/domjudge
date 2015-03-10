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
	input += input2 + "$";
	//cout << input << endl;
	
	bool flag = true;
	
	token tokens[50];
	int index = 0;
	
	for (int i = 0; i < input.length(); i++){
		if (input[i] == ' ' || input[i] == '$' || input[i] == '\r' || input[i] == '\n')
			continue;
		else if (input[i] == 's'){
			//if (flag_s == false){
				token ans;
				ans.type = "strdcl";
				ans.val = "s";
				tokens[index] = ans;
				index++;
				//flag_s = true;
			//}
			/*else {
				flag = false;
				i = input.length();
				break;
			}*/
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
			while (input[i] != '\"' && input[i] != ' ' && input[i] != '$'){
				//if (flag_id == false){
					ans.val += input[i];
					i++;
					//flag_id = true;
				//}
				/*else {
					flag = false;
					cout << "id false" << endl;
					i = input.length();
					break;
				}*/
			}
			i--;
            tokens[index] = ans;
			index++;
			continue;
		}
		else {
			flag = false;
			cout << "else" << endl;
			break;
		}
	}
	//cout << flag_id << endl;
	
	bool flag_id = false;
	if (flag==true) {
        for (int i = 0; i < index; i++){
			switch (i){
				case 0:
					if (tokens[i].type != "strdcl" || tokens[i].val != "s"){
						flag = false;
						i = index;
					}
					break;
				case 1:
					if (tokens[i].type == "id"){
						if (tokens[i].val.length() > 1){
							flag = false;
							i = index;
							break;
						}
					}
					else {
						flag = false;
						i = index;
						break;
					}
					break;
				case 2:
					if (tokens[i].type != "quote"){
						flag = false;
						i = index;
					}
					break;
				case 3:
					if (tokens[i].type != "string"){
						flag = false;
						i = index;
					}
					break;
				case 4:
					if (tokens[i].type != "quote"){
						flag = false;
						i = index;
					}
					break;
				case 5:
					if (tokens[i].type != "print" || tokens[i].val != "p"){
						flag = false;
						i = index;
					}
					break;
				case 6:
					if (tokens[i].type == "id"){
						string val = tokens[i].val;
						for (int j = 0; j < val.length(); j++){
							if ( (val[j] >= 'a' && val[j] <= 'z' && val[j] != 'q' && val[j] != 's') || flag_id == false){
								flag_id = true;
							}
							else {
								flag = false;
								i = index;
								break;
							}
						}
					}
					else {
						flag = false;
						i = index;
						break;
					}
					break;
			}
            
		}
	}
	else cout << "valid input" << endl;
	
	if (flag==true) {
        for (int i = 0; i < index; i++){
			cout << tokens[i].type << " " << tokens[i].val << endl;
		}
	}
	else cout << "valid input" << endl;
	
	
    system("pause");
	return 0;
}
