// GroupCompition1_ProblemC_100502068.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

struct token{
	string type;
	string val;
};



int _tmain(int argc, _TCHAR* argv[])
{
	string input;
	string id="";
	string Ipar="";
	string inum="";
	string rpar="";
	cin >> input;
	bool flag = true;
	input = input + '$';
	token ans;
	int current=0;
	while (input[current] != '$'){
		if (input[current] >= '0' && input[current] <= '9'){
			ans.type = "inum";
			ans.val="";
			while(input[current] >= '0' && input[current] <= '9'){
				ans.val = ans.val + input[current];
				current++;
			}
			inum = inum+ans.val;
		}
		else {
			if (input[current] == '('){
				ans.val="";
				ans.type = "lparenthesis";
				ans.val =  "(";
				current++;
				Ipar =Ipar+"(";
			}
			else if (input[current] == ')'){
				ans.val="";
				ans.type = "rparenthesis";
				ans.val =  ")";
				current++;
				rpar = rpar+"(";
			}
			else if ((input[current] >= 'a' && input[current] <= 'z') || (input[current] >= 'A' && input[current] <= 'Z') || input[current] == '_'){
				ans.type = "id";
				ans.val="";
				while((input[current] >= 'a' && input[current] <= 'z') || (input[current] >= 'A' && input[current] <= 'Z') || input[current] == '_'){
					ans.val = ans.val + input[current];
					current++;
				}
				id = id+ans.val;
			}
			else {
				cout << "invalid input" << endl;
				flag=false;
				break;
			}
		}
	}
	if(flag)
		cout<<"id "<<id<<endl<<"Iparenthesis "<<Ipar<<endl<<"inum "<<inum<<endl<<"rparenthesis "<<rpar<<endl;
		system("pause");
	return 0;
}


