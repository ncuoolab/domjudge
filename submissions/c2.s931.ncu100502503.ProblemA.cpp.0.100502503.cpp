#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;
bool flag = true;
bool valueFlag = false;
char idInput[20];
char assignInput[20];
char valueInput[20];

void Scanner(string sInput, char idInput[20], char assignInput[20], char valueInput[20])
{
	int idCount = 0;
	int assignCount = 0;
	int valueCount = 0;
	int jumpCount = 0;
	int point = 0;
	int valueSpaceCount = 0;
	int idValue = 0;
	int inumValue = 0;


	while(point < sInput.size())
	{
	    //id
		while(jumpCount == 0)
		{
			if(sInput[point] < 'a'|| sInput[point] > 'z')
			{
				flag = false;
				return;
			}

			idInput[idCount] = sInput[point];
			point++;
			idCount++;
			if(idCount > 1)
			{
				flag = false;
				return;
			}

			if(sInput[point] == ' ')
			{
				jumpCount++;
				point++;
				break;
			}
			else if(sInput[point] == '=')
            {
                jumpCount++;
                break;
            }
            else
            {
                flag = false;
                return;
            }

            if(point >=sInput.size())
            {
                flag = false;
                return;
            }
		}
		//assign
		while(jumpCount == 1)
		{
			if(sInput[point] != '=')
			{
				flag = false;
				return;
			}
			assignInput[assignCount] = sInput[point];
			point++;
			assignCount++;
			if(assignCount > 1)
			{
				flag = false;
				return;
			}

			if(sInput[point] == ' ')
			{
			    jumpCount++;
				point++;
				break;
			}
			else if((sInput[point] >= 'a' && sInput[point] <= 'z') || (sInput[point] >= '0' && sInput[point] <= '9') )
            {
                jumpCount++;
                break;
            }
            else {
                flag = false;
                return;
            }

			if(point >=sInput.size())
            {
                flag = false;
                return;
            }

		}

		while(jumpCount == 2)
		{

			if((sInput[point] >= 'a' && sInput[point] <= 'z') || (sInput[point] >= '0' && sInput[point] <= '9') )
			{
                valueFlag = true;
			}
			else if(sInput[point] == ' ')
            {
                point++;
            }
            else
            {
                flag = false;
                return;
            }
            while(valueFlag)
            {
                if(sInput[point] >= 'a' && sInput[point] <= 'z')
				{
					if(idValue > 0 || inumValue !=0)
					{
						flag = false;
						return;
					}
					valueInput[valueCount] = sInput[point];
					valueCount++;
					point++;
					idValue++;
				}
				if(sInput[point] >= '0' && sInput[point] <= '9')
				{
	//last out put inum
                    if((valueSpaceCount != 0) || (idValue != 0))
                    {
                        flag = false;
                        return;
                    }
					valueInput[valueCount] = sInput[point];
					valueCount++;
                    inumValue++;
					point++;
				}
				if(sInput[point] == ' ')
                {
                    valueSpaceCount++;
                    point++;
                }
				if(point >=sInput.size())
					return;
            }

		}


	}
}

int main()
{
	char input[20];

	cin.getline(input, 20);
	Scanner(input, idInput, assignInput, valueInput);
	if(flag == false)
	{
		cout << "invaild input" << endl;
		system("pause");
		return 0;
	}
	cout << "id " << idInput << endl;
	cout << "assign " << assignInput << endl;
	if(valueInput[0] >= 'a' && valueInput[0] <= 'z')
		cout << "id " << valueInput << endl;
	else
		cout << "inum " << valueInput << endl;


	system("pause");
	return 0;
}

