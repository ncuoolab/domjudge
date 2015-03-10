#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

int a=0;
int test;

bool IfLittle(char character)
{
	if(character>=97&&character<=111)
	{
		return true;
	}
	else if(character==113)
	{
		return true;
	}
	else if(character==114)
	{
		return true;
	}
	else if(character>=116&&character<=122)
	{
		return true;
	}
	return false;
}

bool IfLarge(char character)
{
	if(character>=65&&character<=90)
	{
		return true;
	}
	return false;
}

bool IfNumber(char character)
{
	if(character>=48&&character<=57)
	{
		return true;
	}
	return false;
}
bool IfSpace(char character)
{
	if(character==' ')
	{
		return true;
	}
	return false;
}
bool IfGrammar(int paratest)
{
	if(a==0)
	{
		test=0;
	}
	else if(a==1)
	{
		test=1;
	}
	else if(a==2)
	{
		test=2;
	}
	else if(a==3)
	{
		test=3;
	}
	else if(a==4)
	{
		test=2;
	}
	else if(a==5)
	{
		test=4;
	}
	else if(a==6)
	{
		test=1;
	}
	a++;
	if(test==paratest)
	{
		return true;
	}
	else
	{
		cout<<"valid input"<<endl;
		exit(0);
		return false;
	}
}
int main()//112
{ 
	string input;
	string space=" ";
	string holdinput;
	string output="";
	string str="";
	while(getline(cin,holdinput))
	{
		input=input+space+holdinput;
	} 
	int length=input.size();
	for(int a=0;a<length;a++)
	{
		if(input[a]!=' ')
		{
			str=str+input[a];
		}
	} 
	input=str;
	length=input.size();
	string hold="";
	for(int a=0;a<length;a++) 
	{
		if(input[a]=='s')
		{
			output=output+"strdcl "+input[a]+"\n";
			IfGrammar(0);
		}
		else if(input[a]=='\"')
		{
			output=output+"quote "+input[a]+"\n";
			IfGrammar(2);
		}
		else if(input[a]=='p')
		{
			output=output+"print "+input[a]+"\n";
			IfGrammar(4);
		}
		else if((input[a]>=97&&input[a]<=111)||input[a]==113||input[a]==114||(input[a]>=116&&input[a]<=122))
		{
			if(input[a+1]!='\"')
			{
				if(a==length-1)
				{
					if(hold=="")
					{
						output=output+"id "+input[a]+"\n";
						IfGrammar(1);
					}
					else
					{
						hold=hold+input[a];
						output=output+"string "+hold+"\n";
						hold="";
						IfGrammar(3);
					}
				}
				else
				{
					hold=hold+input[a];
				}
			}
			else 
			{
				if(hold=="")
				{
					output=output+"id "+input[a]+"\n";
					IfGrammar(1);
				}
				else
				{
					hold=hold+input[a];
					output=output+"string "+hold+"\n";
					hold="";
					IfGrammar(3);
				}
			}
		}
		else if((input[a]>=65&&input[a]<=90)||(input[a]>=48&&input[a]<=57))
		{
			if(input[a+1]!='\"')
			{
				if(a==length-1)
				{
					hold=hold+input[a];
					output=output+"string "+hold+"\n";
					hold="";
					IfGrammar(3);
				}
				else
				{
					hold=hold+input[a];
				}
			}
			else
			{
				hold=hold+input[a];
				output=output+"string "+hold+"\n";
				hold="";
				IfGrammar(3);
			}
		}
		else
		{
			if(input[a]!=13)
			{
				cout<<"valid input"<<endl;
				exit(0);
			}
		}
   }
	cout<<output;
	system("pause");
	return 0;
}
