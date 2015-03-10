#include<iostream>
#include <string>
#include<cstdlib>
using namespace std;

bool IfLittle(char character)
{
	if((character>=97&&character<=111)||character==113||character==114||(character>=116&&character<=122))
	{
		return true;
	}
}

bool IfLarge(char character)
{
	if(character>=65&&character<=90)
	{
		return true;
	}
}

bool IfNumber(char character)
{
	if(character>=48&&character<=57)
	{
		return true;
	}
}
bool IfSpace(char character)
{
	if(character==' ')
	{
		return true;
	}
}
int main()
{ 
	string input;
	while(getline(cin,input))
	{
		bool flag=false;
		int length=input.size();
		for(int a=0;a<length;a++)
		{
			if(!(input[a]>=97&&input[a]<=122)&&!(input[a]==92)&&!(input[a]==34)&&!IfLarge(input[a])&&!IfNumber(input[a])&&!IfSpace(input[a]))
			{
				flag=true;
			}
		}
		if(flag)
		{
			cout<<"valid input"<<endl;
			flag=false;
		}
		else
		{
			string hold="";
			for(int a=0;a<length;a++) 
			{
				if(input[a]=='s')
				{
					cout<<"strdcl "<<input[a]<<endl;
				}
				else if(input[a]==92||input[a]==34)
				{
					cout<<"quote "<<input[a]<<endl;
				}
				else if(input[a]=='p')
				{
					cout<<"print "<<input[a]<<endl;
				}
				else if((input[a]>=97&&input[a]<=111)||input[a]==113||input[a]==114||(input[a]>=116&&input[a]<=122))
				{
							cout<<"AAAAAAAAAAAAAAAAAAAAAAA: "<<input[a]<<" "<<input[a+1]<<endl;
					//		cout<<input[a]<<endl;
					//		cout<<input[a+1]<<endl;
					//if((IfLittle(input[a+1])||IfLarge(input[a+1])||IfNumber(input[a+1]))&&(!IfSpace(input[a+1])||input[a+1]!='s'||input[a+1]!='p'||input[a+1]!=34)||input[a+1]!=92)
					if(!IfSpace(input[a+1])&&input[a+1]!='s'&&input[a+1]!='p'&&input[a+1]!=34&&input[a+1]!=92)
					{
							cout<<"BBBBBBBBBBBBBBBBBB"<<endl;
						hold=hold+input[a];
					}
					else 
					{
							cout<<"CCCCCCCCCCCCCCCCCCCC: "<<endl;
						if(hold=="")
						{
							cout<<"id "<<input[a]<<endl;
						}
						else
						{
							hold=hold+input[a];
							cout<<"string "<<hold<<endl;
							hold="";
						}
					}
				}
				else if(input[a]>=65&&input[a]<=90)
				{
				//			cout<<"EEEEEEEEEEEEEEEEEEEEE"<<endl;
					if(IfLittle(input[a+1])||IfLarge(input[a+1])||IfNumber(input[a+1])||!IfSpace(input[a+1]))
					{
					//		cout<<"FFFFFFFFFFFFFFFFFFFFFFF"<<endl;
						hold=hold+input[a];
					//		cout<<"GGGGGGGGGGGGGGGGGGGG: "<<hold<<endl;
					}
					else
					{
						if(hold=="")
						{
							cout<<"id "<<input[a]<<endl;
						}
						else
						{
							hold=hold+input[a];
							cout<<"string "<<hold<<endl;
							hold="";
						}
					}
				}
				else if(input[a]>=48&&input[a]<=57)
				{
				//		 cout<<"IIIIIIIIIIIIIIIIII"<<endl;
					if(IfLittle(input[a+1])||IfLarge(input[a+1])||IfNumber(input[a+1])||!IfSpace(input[a+1]))
					{
					//		cout<<"JJJJJJJJJJJJJJJJJJJJJ"<<endl;
						hold=hold+input[a];
					//		cout<<"KKKKKKKKKKKKKKKKKKKK: "<<hold<<endl;
					}
					else
					{
						if(hold=="")
						{
							cout<<"id "<<input[a]<<endl;
						}
						else
						{
							hold=hold+input[a];
							cout<<"string "<<hold<<endl;
							hold="";
						}
					}
				}
				else
				{
				//	cout<<"LLLLLLLLLLLLLLLLLLL: "<<hold<<"   EEEEE"<<endl;
					if(hold!="") 
					{
						cout<<"string "<<hold<<endl;
						hold="";
					}
				}
			}
    	}
	}
	system("pause");
	return 0;
}
