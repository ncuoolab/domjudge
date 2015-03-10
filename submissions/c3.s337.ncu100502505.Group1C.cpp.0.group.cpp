#include<iostream>
#include<string>
using namespace std;

int main()
{
	string input;
	string output;
	string num;
	string id;
	bool flag = false;

	getline(cin,input);

	for(int i=0;i<input.size();i++)
	{
		if(flag)
		{
			if(input[i] >= '0' && input[i] <= '9')
			{
				num = num + input[i];
			}else if(input[i] == ')')
			{
				output = output + "inum " + num + '\n' + "rparenthesis " +input[i] + '\n';
				flag = false;
			}else{
				output = "invalid input";
				break;
			}
		}else if(input[i] == ' ' || input[i] == '\r' || input[i] == '\n')
		{
		
		}
		else if((input[i] >='a' && input[i] <='z') || (input[i] >='A' && input[i] <= 'Z') || input[i] == '_' )
		{
			id = id + input[i];
		}else if(input[i] == '(')
		{
			output = output + "id " + id + '\n';
			output = output + "lparenthesis " + input[i] + '\n';
			flag = true;
		}else
		{
			output = "invalid input";
			break;
		}
	}

	cout << output;

	return 0;
}