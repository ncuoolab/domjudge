#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

char parenthesis[5];
char id[45];
char para[45];
bool flag = true;

void Scanner(string sInput, char idInput[45], char parenthesisInput[5], char paraInput[45])
{
	string paraString;
	int parenthesisCount = 0;
	int idCount = 0;
	int paraCount = 0;
	int spaceCount = 0;
	int point = 0;
	int paraId = 0;
	int paraInum = 0;
						
					if(sInput[sInput.size()-1] != ')')
					{
						flag = false;
						return;
					}
	if(sInput.size() < 1)
	{
		flag = false;
		return;
	}
	
	//id
	while(point < sInput.size())
	{
		while(parenthesisCount == 0)
		{
			if((sInput[point] >= 'a' && sInput[point] <= 'z') || (sInput[point] >= 'A' && sInput[point] <= 'Z') || sInput[point] == '_' )
			{
				idInput[idCount] = sInput[point];
				point++;
				idCount++;
				if(idCount < 1)
				{
					flag = false;
					return;
				}
			

			}
			else
			{
				flag = false;
				return;
			}
		if(sInput[point] == ' ')
		{
			point++;
		}
		if(sInput[point] == '(')
		{	parenthesis[parenthesisCount] = sInput[point];
			parenthesisCount++;
			point++;
		}

		}
		//Func

if(sInput[point] == ' ')
					{
						point++;
					}

		while(parenthesisCount == 1)
		{		
			//PARA
			if((sInput[point] >= 'a' && sInput[point] <= 'z') || (sInput[point] >= 'A' && sInput[point] <= 'Z') || sInput[point] == '_' || 
				(sInput[point] >= '0' && sInput[point] <= '9') || sInput[point] == ')'|| sInput[point] == ' ')
			{

				if(sInput[point] == ' ')
				{
					point++;
				}
				if(sInput[point] == ')')
				{
					parenthesis[parenthesisCount] = sInput[point];
					parenthesisCount++;


					paraString.append(para);
					if(paraString.empty() == true)
					{
						flag = false;
						return;
					}					
					return;
				}

				if((sInput[point] >= 'a' && sInput[point] <= 'z') || (sInput[point] >= 'A' && sInput[point] <= 'Z') || sInput[point] == '_')
				{
					if(paraInum != 0)
					{
						flag = false;
						return;
					}
					para[paraCount] = sInput[point];
					paraCount++;
					point++;
					paraId++;
				}

				if(sInput[point] >= '0' && sInput[point] <= '9') 
				{
					if(paraId != 0)
					{
						flag = false;
						return;
					}
					para[paraCount] = sInput[point];
					paraCount++;
					point++;
					paraInum++;
				}
				if(point >= sInput.size())
				{
					return;
				}
			}
			else
			{
				flag = false;
				return;
			}
		}
	}
}

int main()
{
	char input[100];
	cin.getline(input, 100);

	Scanner(input, id, parenthesis, para);

	if(flag == false)
	{
		cout << "invalid input" << endl;
		system("pause");
		return 0;
	}

	cout << "id " << id << endl;
	cout << "lparenthesis " << parenthesis[0] << endl;
	if((para[0] >= 'a' && para[0] <= 'z') || (para[0] >= 'A' && para[0] <= 'Z') || para[0] == '_')
	{
		cout << "id " << para << endl;
	}

	if(para[0] >= '0' && para[0] <= '9') 
	{
		cout << "inum " << para << endl;
	}
	
	cout << "rparenthesis " << parenthesis[1] << endl;

	system("pause");
	return 0;
}
