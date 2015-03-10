#include<iostream>
#include<string>
using namespace std;

int main()
{
	string input;
	while(true)
	{
    getline(cin,input);
	bool flag = false; 
	string a = "";
	for(int i=0;i<input.length();i++)
	{
		if(flag)
		{
			if(input[i] >='a' && input[i]<='z')
			{
				a=a+input[i];
			}
			else if(input[i] >='A' && input[i]<='Z')
			{
				a=a+input[i];
			}
			else if(input[i] >='0' && input[i]<='9')
			{
				a=a+input[i];
			}
			else if(input[i] == '*')
			{
				a=a+input[i];
			}
			else if(input[i] == '"' || input[i] == '\\')
			{
				cout << "string " << a << endl;
				cout << "quote " << input[i] << endl;
			}
		}else{
			if(input[i] != ' ')
			{
				/*if(input[0] != 's' || input[0] != 'p')
				{
					cout <<"valid input" << endl;
					break;
				}*/
				if(input[i] == 's')
					cout << "strdcl "  << input[i] << endl;
				else if(input[i] >='a' && input[i]<='o')
					cout << "id " << input[i] << endl;
				else if(input[i] =='q' || input[i] =='r')
					cout << "id " << input[i] << endl;
				else if(input[i] >='t' && input[i] <= 'z')
					cout << "id " << input[i] << endl;
				else if(input[i] == '"' || input[i] == '\\')
				{
					cout << "quote " << input[i] << endl;
					flag = true;
				}
				else if(input[i] == 'p')
					cout << "print " << input[i] << endl;
				else
				{
					cout <<"valid input" << endl;
					break;
				}
			}
		}
	}
	}

	return 0;
}
