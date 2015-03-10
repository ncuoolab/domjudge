
#include <string>
#include <iostream>
#include<cstdlib>

using namespace std;

struct token{
	string type;
	string val;
};



int main()
{
	string input;
	cin >> input;
	input = input + '$';
	token ans;
	int current=0;
	bool flag = false;

	while (input[current] != '$'){
		if ( (input[current]>='0'&&input[current]<='9') ||
			 (input[current]>='a'&&input[current]<='z') ||
			 (input[current]>='A'&&input[current]<='Z') ||
			 (input[current] == '_') ||  (input[current] == '(') ||  (input[current] == ')') || input[current] == ' ') {
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

		if (input[current] >= '0' && input[current] <= '9' || input[current] == ' '){
			ans.type = "inum";
			ans.val="";
			while(input[current] >= '0' && input[current] <= '9' || input[current] == ' '){
				ans.val = ans.val + input[current];
				current++;
			}
			cout << ans.type << " " << ans.val << endl;
		}
		else {
			if (input[current] == '(' || input[current] == ' '){
				ans.val="";
				ans.type = "lparenthesis";
				ans.val =  "(";
				current++;
				cout << ans.type << " " << ans.val << endl;
			}
			else if (input[current] == ')' || input[current] == ' '){
				ans.val="";
				ans.type = "rparenthesis";
				ans.val =  ")";
				current++;
				cout << ans.type << " " << ans.val << endl;
			}
			else if ((input[current] >= 'a' && input[current] <= 'z') || (input[current] >= 'A' && input[current] <= 'Z') || input[current] == '_' || input[current] == ' '){
				ans.type = "id";
				ans.val="";
				while((input[current] >= 'a' && input[current] <= 'z') || (input[current] >= 'A' && input[current] <= 'Z') || input[current] == '_' || input[current] == ' '){
					ans.val = ans.val + input[current];
					current++;
				}
				cout << ans.type << " " << ans.val << endl;
			}
		}
	}
	}
	else cout << "invalid input" << endl;
	system("pause");
	return 0;
}

