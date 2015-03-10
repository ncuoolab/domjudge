#include <iostream>
#include <string>
using namespace std;

int main()
{
	string id = "";
	string lparenthesis = "";
	string rparenthesis = "";
	string inum = "";
	string c ;
	int err = 0 ;
	int number = 0;
	int number1 = 1000;
	cin >> c;
	int a = c.length();
	for (int i = 0 ; i < a ; i++)
	{
		//char a = ' ';
		if(int(c[i]) >= 65 && int(c[i]) <= 122)  //a-Z
		{
			id += c[i];
			number = i;
			if (number > number1)
			{
				err = 1;
			}
		}
		else if(int(c[i]) >= 48 && int(c[i]) <= 57) //0-9
		{
			inum += c[i];
			number1 = i;
		}
		else if(int(c[i]) == 40)//(
		{
			lparenthesis += c[i];
			number1 = i;
		}
		else if(int(c[i]) == 41) //)
		{
			rparenthesis += c[i];
			number1 = i;
		}
		else if(int(c[i]) == 32)// 
		{
			number1 = i;
		}
	}
	if(err ==1 )
	{
		cout << "invalid input";
	}
	else
	{
		cout << "id " << id.c_str() << endl;
		cout << "lparenthesis " << lparenthesis.c_str() << endl;
		cout << "inum " << inum.c_str() << endl ;
		cout << "rparenthesis " << lparenthesis.c_str() << endl;
	
	}
	system("pause");

}
