#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

char c;
bool flag;
string output = "";
void Dcl();
void Stmt();
void Id();

int main()
{
	Dcl();
	Stmt();

	cout << output << endl;

	system("pause");
	
	return 0;
}

void Dcl()
{
	cin.get(c);
	if(c != 'l')
	{
		cout << "invalid input" << endl;
		exit(0);
	}
	else
	{
		cin.get(c);
		if(c <= '0' || c >= '9')
		{
			cout << "invalid input" << endl;
			exit(0);
		}
		else
		{
			output += "level l";
			output += c;

			while(true)
			{
				cin.get(c);
				if(c >= '0' && c <= '9')
					output += c;
				else
				{
					while(c == ' ')
						cin.get(c);

					output += '\n';
					break;
				}
			}

			Id();
		}
	}	
}
void Stmt()
{
	if(c != 'b')
	{
		cout << "invalid input" << endl;
		exit(0);
	}
	else
	{
		output += "battle ";
		output += c;
		output += '\n';

		cin.get(c);
		while(c == ' ')
			cin.get(c);
		Id();		
	}
}
void Id()
{
	if(c >= '0' && c <= '9')
	{
		output += "cid ";
		output += c;

		while(true)
		{
			cin.get(c);
			if(c >= '0' && c <= '9')
				output += c;
			else
			{
				while(c == ' ')
					cin.get(c);

				output += '\n';
				break;
			}
		}
	}
	else if(c >= 'A' && c <= 'Z')
	{
		output += "FirstName ";
		output += c;

		while(true)
		{
			cin.get(c);
			if(c >= 'a' && c <= 'z')
				output += c;
			else
			{
				while(c == ' ')									
					cin.get(c);

				output += '\n';
				break;
			}
		}

		if(c <= 'a' || c >= 'z' || c == 'b')
		{
			cout << "invalid input" << endl;
			exit(0);
		}

		output += "LastName ";
		output += c;

		while(true)
		{
			cin.get(c);			

			if(c >= 'a' && c <= 'z' && c != 'b')
				output += c;
			else
			{
				while(c == ' ' || c == '\n')				
					cin.get(c);

				output += '\n';
				break;
			}
		}
	}
	else
	{
		cout << "invalid input" << endl;
		exit(0);
	}
}