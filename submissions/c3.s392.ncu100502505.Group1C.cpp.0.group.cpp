#include<iostream>
#include<string>
using namespace std;

int main()
{
	string input;
	string output;
	string num;
	string id;
	string sent;
	string id2;
	bool flag = false;
	bool check = false;

	while(getline(cin,sent))
	{
		input = input + sent;
	}

	for(int i=0;i<input.size();i++)
	{
		if(flag)
		{
			if(input[i] == ' ' || input[i] == '\r' || input[i] == '\n')
			{
			}
			else if(input[i] >= '0' && input[i] <= '9')
			{
				num = num + input[i];
				check = true;
			}else if((input[i] >='a' && input[i] <='z') || (input[i] >='A' && input[i] <= 'Z') || input[i] == '_')
			{
				id2 = id2 + input[i];

			}else if(check == true && input[i] == ')')
			{
				output = output + "inum " + num + '\n' + "rparenthesis " +input[i] + '\n';
				flag = false;
			}else if(check == false && input[i] == ')')
			{
				output = output + "id " + id2 + '\n' + "rparenthesis " +input[i] + '\n';
				flag = false;
			}
			else{
				output = "invalid input\n";
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
			output = "invalid input\n";
			break;
		}
	}

	bool c = false;
	
	for(int i=0;i<input.size();i++)
	{
		if(input[i] == '(' || input[i] == ')'  )
		{
			c = true;		
		}else
		{
			c = false;
		}
	
	}

	if(c == false)
	{
		output = output + "id " + id + '\n';
	}

	cout << output;

	return 0;
}