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
	/*if((character>=97&&character<=111)||character==113||character==114||(character>=116&&character<=122))
	{
		return true;
	}*/
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
	cout<<a<<" "<<test<<" "<<paratest<<endl;
	a++;
	if(test==paratest)
	{
		return true;
	}
	else
	{
		cout<<"RRRRRRRRRRRRRR"<<endl;
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
	//cout<<input<<endl;
	bool flag=false;
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
	//cout<<input<<endl;
	/*for(int a=0;a<length;a++)
	{
		if(input[a]<97||input[a]>122)
		{
			if(input[a]!='\"')
			{
				if(!IfLarge(input[a]))
				{
					if(!IfNumber(input[a]))
					{
						if(!IfSpace(input[a]))
						{
							cout<<input[a]<<endl;
							flag=true;
						}
					}
				}
			}
		}
		/*if((input[a]>=97&&input[a]<=122)&&!(input[a]==92)&&!(input[a]==34)&&!IfLarge(input[a])&&!IfNumber(input[a])&&!IfSpace(input[a]))
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
	{*/
		string hold="";
		for(int a=0;a<length;a++) 
		{
			if(input[a]=='s')
			{
				//cout<<"strdcl "<<input[a]<<endl;
				output=output+"strdcl "+input[a]+"\n";
				IfGrammar(0);
			}
			else if(input[a]=='\"')
			{
				//cout<<"quote "<<input[a]<<endl;
				output=output+"quote "+input[a]+"\n";
				IfGrammar(2);
			}
			else if(input[a]=='p')
			{
				//cout<<"print "<<input[a]<<endl;
				output=output+"print "+input[a]+"\n";
				IfGrammar(4);
			}
			else if((input[a]>=97&&input[a]<=111)||input[a]==113||input[a]==114||(input[a]>=116&&input[a]<=122))
			{
						//cout<<"AAAAAAAAAAAAAAAAAAAAAAA: "<<input[a]<<endl;
						//	cout<<input[a]<<endl;
						//	cout<<input[a+1]<<endl;
					//if((IfLittle(input[a+1])||IfLarge(input[a+1])||IfNumber(input[a+1]))&&(!IfSpace(input[a+1])||input[a+1]!='s'||input[a+1]!='p'||input[a+1]!=34)||input[a+1]!=92)
				if(input[a+1]!='\"')
				{
					//	cout<<"BBBBBBBBBBBBBBBBBBBBBBB: "<<input[a]<<endl;
					if(a==length-1)
					{
					//	cout<<"CCCCCCCCCCCCCCCCCCCCCCCCCC: "<<input[a]<<endl;
						if(hold=="")
						{
					//	cout<<"DDDDDDDDDDDDDDDDDDDD: "<<input[a]<<endl;
							//cout<<"id "<<input[a]<<endl;
							output=output+"id "+input[a]+"\n";
							IfGrammar(1);
						}
						else
						{
					//	cout<<"EEEEEEEEEEEEEEEEEE: "<<input[a]<<endl;
							hold=hold+input[a];
							//cout<<"string "<<hold<<endl;
							output=output+"string "+hold+"\n";
							hold="";
							IfGrammar(3);
						}
					}
					else
					{
					//	cout<<"FFFFFFFFFFFFFFFFFF: "<<input[a]<<endl;
						hold=hold+input[a];
					}
				}
				else 
				{
					//	cout<<"GGGGGGGGGGGGG: "<<input[a]<<endl;
					if(hold=="")
					{
					//	cout<<"HHHHHHHHHHHHHHHHHHH: "<<input[a]<<endl;
						//cout<<"id "<<input[a]<<endl;
						output=output+"id "+input[a]+"\n";
						IfGrammar(1);
					}
					else
					{
					//	cout<<"IIIIIIIIIIIIIIIIII: "<<input[a]<<endl;
						hold=hold+input[a];
						//cout<<"string "<<hold<<endl;
						output=output+"string "+hold+"\n";
						hold="";
						IfGrammar(3);
					}
				}
			}
			else if((input[a]>=65&&input[a]<=90)||(input[a]>=48&&input[a]<=57))
			{
						//cout<<"JJJJJJJJJJJJJJJJJJJJJ: "<<input[a]<<endl;
				if(input[a+1]!='\"')
				{
					//	cout<<"KKKKKKKKKKKKKKKKKKK: "<<input[a]<<endl;
					if(a==length-1)
					{
				//	cout<<"LLLLLLLLLLLLLLLLLLLLL: "<<input[a]<<endl;
						hold=hold+input[a];
						//cout<<"string "<<hold<<endl;
						output=output+"string "+hold+"\n";
						hold="";
						IfGrammar(3);
					}
					else
					{
						//cout<<"MMMMMMMMMMMMMMMMMM: "<<input[a]<<endl;
						hold=hold+input[a];
					}
				}
				else
				{
						//cout<<"NNNNNNNNNNNNNNNNNNN: "<<input[a]<<endl;
					hold=hold+input[a];
					//cout<<"string "<<hold<<endl;
					output=output+"string "+hold+"\n";
					hold="";
					IfGrammar(3);
				}
			}
			else
			{
				if(input[a]!=' ')
				{
	cout<<output;
		cout<<"WWWWWWWWWWWWWWWWWW"<<endl;
					cout<<"valid input"<<endl;
					exit(0);
				}
				/*cout<<"valid input"<<endl;
				exit(0);*/
						//cout<<"OOOOOOOOOOOOOOOOOOO: "<<input[a]<<" EEE"<<endl;
				//	cout<<"LLLLLLLLLLLLLLLLLLL: "<<hold<<"   EEEEE"<<endl;
				//if(hold!="") 
				//{
					//cout<<"string "<<hold<<endl;
					//output=output+"string "+hold+"\n";
					//hold="";
				//}
			}
		//}
   }
	cout<<output;
	system("pause");
	return 0;
}
