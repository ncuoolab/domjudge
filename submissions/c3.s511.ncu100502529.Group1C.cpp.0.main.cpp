#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

struct Token
{
	string type;
	string value;
} token1, token2, token3, token4;

void scan(char *input, int current);
void print(bool noPara);
void Error();

int main()
{
	string temp;
	string temp2;
	//getline(cin, temp, '\0');
	while(getline(cin, temp2))
	{
		temp.append(temp2);
	}

	char *input = new char[temp.size()+1];
	input[temp.size()] = '\0';
	memcpy(input,temp.c_str(),temp.size());
	int current = 0;

	scan(input, current);

	system("pause");
	return 0;
}

void scan(char *input, int current)
{
	int c = 1;
	bool isError = false;
	bool noPara = false;
	string temp;

	while(input[current] != '\0')
	{
		switch(c)
		{
		case 1:
			if( (input[current] >= 'a' && input[current] <= 'z')
				|| (input[current] >= 'A' && input[current] <= 'Z')
				|| input[current] == '_')
			{
				temp.append(1, input[current]);
				current++;
				while( (input[current] >= 'a' && input[current] <= 'z')
						|| (input[current] >= 'A' && input[current] <= 'Z')
						|| input[current] == '_')
				{
					temp.append(1, input[current]);
					current++;
				}
				token1.type = "id";
				token1.value = temp;
				temp = "";
				if(input[current] == '\0')
				{
					isError = true;
				}
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
			if(input[current] == '(')
			{
				token2.type = "lparenthesis";
				token2.value = input[current];
				current++;
				if(input[current] == '\0')
				{
					isError = true;
				}
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
			if(input[current] >= '0' && input[current] <= '9')
			{
				temp.append(1, input[current]);
				current++;
				while(input[current] >= '0' && input[current] <= '9')
				{
					temp.append(1, input[current]);
					current++;
				}
				token3.type = "inum";
				token3.value = temp;
				//token3.value = atoi(temp.c_str());	//string to int
				if(input[current] == '\0')
				{
					isError = true;
				}
				c = 4;
			}
			else if( (input[current] >= 'a' && input[current] <= 'z')
					|| (input[current] >= 'A' && input[current] <= 'Z')
					|| input[current] == '_')
			{
				temp.append(1, input[current]);
				current++;
				while( (input[current] >= 'a' && input[current] <= 'z')
						|| (input[current] >= 'A' && input[current] <= 'Z')
						|| input[current] == '_')
				{
					temp.append(1, input[current]);
					current++;
				}
				token3.type = "id";
				token3.value = temp;
				if(input[current] == '\0')
				{
					isError = true;
				}
				c = 4;
			}
			else if(input[current] == ')')
			{
				//token3.type = "";
				//token3.value = "";
				noPara = true;
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
			if(input[current] == ')')
			{
				token4.type = "rparenthesis";
				token4.value = input[current];
				current++;
				c = 5;
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
		case 5:
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
		print(noPara);
	}
}

void print(bool noPara)
{
	cout << token1.type << " ";
	cout << token1.value << endl;

	cout << token2.type << " ";
	cout << token2.value << endl;
	
	if(!noPara)
	{
		cout << token3.type << " ";
		cout << token3.value << endl;
	}

	cout << token4.type << " ";
	cout << token4.value << endl;
}

void Error()
{
	cout << "invalid input" << endl;
}