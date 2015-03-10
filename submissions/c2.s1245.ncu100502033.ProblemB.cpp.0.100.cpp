#include <iostream>
#include <string>
using namespace std;

int main()
{
	string strdcl = "";
	string id = "";
	string quote = "";
	string str  = "";
	string quote2 = "";
	string print = "";
	string id2 = "";
	string in ;
	string in2 ;
	string s ;
	int err = 0;
	int a ;
	int number = 0;
	getline(cin,in);
	getline(cin,in2);
	a = in.length();
	for (int i = 0 ; i < a ; i++)
	{
		if (int(in[i]) == 115)
		{
			strdcl = in[i] ;
			number = i + 1;
			i = a;
		}
		else if(int(in[i]) == 32)
		{
		}
		else 
		{
			err = 1;
		}
	}
	for (int i = number ; i < a ; i++)
	{
    	if ((int(in[i]) >= 97 && int(in[i]) <= 113) || (int(in[i]) >= 116 && int(in[i]) <= 122) )
		{
			id = in[i] ;
			number = i + 1;
			i = a;
		}
		else if(int(in[i]) == 32)
		{
		}
		else 
		{
			err = 1;
		}
	}
	for (int i = number ; i < a ; i++)
	{
		if(int(in[i]) == 34)
		{
			quote = in[i] ; 
			number = i + 1;
			i = a;
		}
		else if(int(in[i]) == 32)
		{
		}
		else 
		{
			err = 1;
		}
	}
	for (int i = number ; i < a ; i++)
	{
		if((int(in[i]) >= 48 && int(in[i]) <= 57) || (int(in[i]) >=65 && int(in[i]) <= 90) || (int(in[i]) >= 97 && int(in[i]) <= 122 ))
		{
			str += in[i];
		}
		else if(int(in[i]) == 32)
		{
		}
		else if(int(in[i]) == 34)
		{
			number = i;
			i = a;
		}
		else 
		{
			err = 1;
		}
	}
	for (int i = number ; i < a ; i++)
	{
		if(int(in[i]) == 34)
		{
			quote2 = in[i] ; 
			number = i + 1;
			i = a;
		}
		else if(int(in[i]) == 32)
		{
		}
		else 
		{
			err = 1;
		}
	}
	a = in2.length();
	for (int i = 0 ; i < a ; i++)
	{
		if(int(in2[i]) == 112)
		{
			print = in2[i];
			number = i + 1;
			i = a;
		}
		else if(int(in2[i]) == 32)
		{
		}
		else 
		{
			err = 1;
		}
	}
	for (int i = number ; i < a ; i++)
	{
    	if ((int(in2[i]) >= 97 && int(in2[i]) <= 113) || (int(in2[i]) >= 116 && int(in2[i]) <= 122) )
		{
			id2 = in2[i] ;
			number = i + 1;
			i = a;
		}
		else if(int(in2[i]) == 32)
		{
		}
		else 
		{
			err = 1;
		}
	}
	if(err == 1 || id2.length() == 0)
	{
		cout << "valid input";
	}
	else if(err == 0 )
	{

		cout << "strdcl " << strdcl << endl ;
		cout << "id " << id << endl ;
		cout << "quote " << quote << endl ;
		if(str.length() != 0)
		{
			cout << "string " << str << endl ;
		}
		cout << "quote " << quote2<< endl ;
		cout << "print " << print << endl ;
		cout << "id " << id2 << endl;
	}
	system("pause");
}