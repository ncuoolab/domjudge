#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;
int main()
{
	string in;
	string id="";
	string inum="";
	getline(cin,in);
	for(unsigned int i=0;i<in.length();i++)
	{
		if(!(in[i]>=97&&in[i]<=122)&&!(in[i]==32)&&!(in[i]==61)&&!(in[i]>=48&&in[i]<=57))
		{
			cout<<"valid input";
			system("pause");
			return 0;
		}
		if(in[i]>=97&&in[i]<=122)
		{
			if(i==in.length()-1)
				;
			else if(in[i+1]!=32)
			{
				cout<<"valid input";
				system("pause");
				return 0;
			}
		}
		else if(in[i]==61)
		{
			if(i==in.length()-1)
				;
			else if(in[i+1]!=32)
			{
				cout<<"valid input";
				system("pause");
				return 0;
			}
		}
		else if(in[i]>=48&&in[i]<=57)
		{
			if(i==in.length()-1)
				;
			else if((in[i+1]!=32)&&!(in[i+1]>=48&&in[i+1]<=57))
			{
				cout<<"valid input";
				system("pause");
				return 0;
			}

		}
	}
	for(unsigned int i=0;i<in.length();i++)
	{
		if(in[i]>=97&&in[i]<=122)
		{
			if(i==in.length()-1)
			{
				cout<<"id "<<in[i]<<endl;
				system("pause");
				return 0;
			}
			else if(in[i+1]!=32)
			{
				cout<<"valid input";
				system("pause");
				return 0;
			}
			else
				cout<<"id "<<in[i]<<endl;
		}
		else if(in[i]==61)
		{
			if(i==in.length()-1)
			{
				cout<<"assign "<<in[i]<<endl;
				system("pause");
				return 0;
			}
			else if(in[i+1]!=32)
			{
				cout<<"valid input";
				system("pause");
				return 0;
			}
			else
			{
			    cout<<"assign ="<<endl;
			}
		}
		else if(in[i]>=48&&in[i]<=57)
		{
			if(i==in.length()-1)
			{
				inum+=in[i];
				cout<<"inum "<<inum<<endl;
			}
			else if(in[i+1]>=48&&in[i+1]<=57)
			{
				inum+=in[i];
			}
			else if((in[i+1]!=32)&&!(in[i+1]>=48&&in[i+1]<=57))
			{
				cout<<"valid input";
				system("pause");
				return 0;
			}
			else if(in[i+1]==32)
			{
				inum+=in[i];
				cout<<"inum "<<inum<<endl;
				inum="";
			}
		}
		else
			;//do nothing
	}
	system("pause");
	return 0;
}

