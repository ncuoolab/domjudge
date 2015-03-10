#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;

union U
{
	char c;
	int i;
};

struct Token
{
	string type;
	U value;
	bool isChar;	//id,assign || inum
} token1, token2, token3;

void scan(char *input, int current);
void print();
void Error();

int main()
{
	//cout << "Please input an assignment(ex:x=1):" << endl;
	string temp;
	getline(cin, temp);
	
	char *input = new char[temp.size()+1];
	input[temp.size()] = '\0';
	memcpy(input,temp.c_str(),temp.size());
	int current = 0;

	//process
	scan(input, current);

	system("pause");
	return 0;
}

void scan(char *input, int current)
{
	int c = 1;
	bool isError = false;
	string temp;

	while(input[current] != '\0')
	{
		switch(c)
		{
		case 1:
			if(input[current] >= 'a' && input[current] <= 'z')	//'a':97 'z':122
			{
				token1.type = "id";
				token1.value.c = input[current];
				token1.isChar = true;
				current++;
				c = 2;
			}
			else if(input[current] == ' ')
			{
				current++;
			}
			else
			{
				isError = true;
			}
			break;
		case 2:
			if(input[current] == '=')
			{
				token2.type = "assign";
				token2.value.c = input[current];
				token2.isChar = true;
				current++;
				c = 3;
			}
			else if(input[current] == ' ')
			{
				current++;
			}
			else
			{
				isError = true;
			}
			break;
		case 3:
			if(input[current] >= '0' && input[current] <= '9')	//'0':48 '9':57
			{
				temp.append(1, input[current]);	//add input[current] to temp once
				current++;
				while(input[current] >= '0' && input[current] <= '9')
				{
					temp.append(1, input[current]);
					current++;
				}
				token3.type = "inum";
				token3.value.i = atoi(temp.c_str());	//string to int
				token3.isChar = false;
				c = 4;
			}
			else if(input[current] >= 'a' && input[current] <= 'z')
			{
				token3.type = "id";
				token3.value.c = input[current];
				token3.isChar = true;
				current++;
				c = 4;
			}
			else if(input[current] == ' ')
			{
				current++;
			}
			else
			{
				isError = true;
			}
			break;
		case 4:
			if(input[current] == ' ')
			{
				current++;
			}
			else
			{
				isError = true;
			}
			break;
		default:
			break;
		}

		if(isError)
		{
			break;
		}
	}

	if(isError)
	{
		Error();
	}
	else
	{
		print();
	}
}

void print()
{
	cout << token1.type << " ";
	if(token1.isChar)
	{
		cout << token1.value.c << endl;
	}
	else
	{
		cout << token1.value.i << endl;
	}

	cout << token2.type << " ";
	if(token2.isChar)
	{
		cout << token2.value.c << endl;
	}
	else
	{
		cout << token2.value.i << endl;
	}

	cout << token3.type << " ";
	if(token3.isChar)
	{
		cout << token3.value.c << endl;
	}
	else
	{
		cout << token3.value.i << endl;
	}
}

void Error()
{
	cout << "Invalid input." << endl;
}