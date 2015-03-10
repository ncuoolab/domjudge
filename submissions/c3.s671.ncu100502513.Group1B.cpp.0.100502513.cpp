#include<cstdlib>
#include<iostream>
#include<string>
using namespace std;

void scanner(string);
bool matchdig(char);
int matchcase(char);
int matchname(string);
bool matchcid(string);
bool matchle(string);
bool SFG(int);

string ter[10];
int tokens[6];

int main()
{
	string input;
	int count=0;
	bool ready = false;
	while(cin>>input)
	{
		if(!matchle(input) && count==0)
		{
			cout<<"invalid input";
			return 0;
		}
		else if(count==1)
		{
			if(input=="b" || matchname(input)==2 || matchle(input))
			{
				cout<<"invalid input";
				return 0;
			}
		}
		if(tokens[count-1]==2)
		{	
			if(tokens[count]!=3)
			{
				cout<<"invalid input";
				return 0;
			}
		}

		scanner(input);	
		if(input=="b")
		{
			ready = true;
		}
		if(ready==true)
		{
			if(tokens[count]==4)
				break;
			else if(tokens[count-1]==2 && tokens[count]==3)
				break;
		}
		count++;
	}

	if(SFG(count))
	{
		for(int i=0;i<count+1;i++)
		{
			cout<<ter[i]<<endl;
		}
	}
	else
		cout<<"invalid input"<<endl;
	
	system("pause");
	return 0;
}

void scanner(string input)
{
	static int count=0;
	if(input=="b")
	{
		tokens[count]=5;  //battle
		ter[count++] = "battle "+input;
	}
	else if(matchle(input))
	{
		tokens[count] = 1;   //level
		ter[count++] = "level "+input;
	}
	else if(matchname(input)==1)
	{
		tokens[count] = 2;   //firstname
		ter[count++] = "FirstName "+input;
	}
	else if(matchname(input)==2)
	{
		tokens[count] = 3;  //lastname
		ter[count++] = "LastName "+input;
	}
	else if(matchcid(input))
	{
		tokens[count] = 4;  //cid
		ter[count++] = "cid "+input;
	}
	else
	{
		cout<<"invalid input"<<endl;
	}
}

int matchcase(char s)
{
		if(s-'a'>=0 && s-'z'<=0)
			return 0;
		else if(s-'A'>=0 && s-'Z'<=0)
			return 1;
		else
			return 3;
	return 3;
}


bool matchdig(char s)
{
	if(s-'0'>=0 && s-'9'<=0)
		return true;
	return false;
}

bool matchle(string s)
{
	if(s[0]=='l')
	{
		if(s.length()>1)
		{
			for(int j=1;j<(signed)s.length();j++)
			{
				if(!matchdig(s[j]))
					return false;
			}
			return true;
		}
		else
			return false;
	}
	else
		return false;
}


int matchname(string s)
{
	if(matchcase(s[0])==1)
	{
		if(s.length()>1)
		{
			for(int j=1;j<(signed)s.length();j++)
			{
				if(matchcase(s[j])==1)
				{
					return 3;
				}
				else if(matchdig(s[j]))
				{
					return 3;
				}
			}
			return 1;
		}
		return 1;
	}
	else if (matchcase(s[0])==0 && s[0]!='b')
	{
		if(s.length()>1)
		{
			for(int j=1;j<(signed)s.length();j++)
			{
				if(matchcase(s[j])==1)
				{
					return 3;
				}
				else if(matchdig(s[j]))
				{
					return 3;
				}
				else if(s[j]=='b')
					return 3;
			}
			return 2;
		}
		return 2;
	}
	return 3;
}

bool matchcid(string s)
{
	for(int i=0;i<(signed)s.length();i++)
	{
		if(!matchdig(s[i]))
			return false;
	}
	return true;
}

bool SFG(int count)
{	
	if(tokens[0]!=1)
		return false;
	for(int i=1;i<count;i++)
	{
		if(tokens[i]==1)
			return false;
	}
	if(tokens[1]==2 && tokens[2]==3 )
	{
		if(tokens[3]!=5)
			return false;
		if(tokens[count]==4)
			return true;
		else if(tokens[count-1]==2 || tokens[count]==3)
			return true;
		else
			return false;
	}
	if(tokens[1]==4)
	{
		if(tokens[2]!=5)
			return false;
		if(tokens[count]==4)
			return true;
		else if(tokens[count-1]==2 || tokens[count]==3)
			return true;
		else
			return false;
	}
	return true;
}
		