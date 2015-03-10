#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;
int main()
{
	int flag=0;
	string input,stream;
	int l=0,r=0;
	int outside,inside;
	cin>>input;
	for(int i=0;i<input.length();i++)
	{
		if(((input[i]-'a'>=0&&input[i]-'z'<=0)||(input[i]-'A'>=0&&input[i]-'Z'<=0)||input[i]-'_'==0))
		{
			stream=stream+input[i];
		}
		else if(input[i]-'('==0)
		{
			stream=stream+input[i];
			outside=i;
			l=1;
		}
		else if(l==1&&((input[i]-'a'>=0&&input[i]-'z'<=0)||(input[i]-'A'>=0&&input[i]-'Z'<=0)||input[i]-'_'==0||(input[i]-'0'>=0&&input[i]-'9'<=0)))
		{
			stream=stream+input[i];
		}
		else if(input[i]-')'==0)
		{
			inside=i;
			stream=stream+input[i];
			break;
		}
		else 
		{
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		cout<<"id ";
		for(int i=0;i<outside;i++)
			cout<<stream[i];
		cout<<endl;
		cout<<"lparenthesis  ("<<endl;
		cout<<"inum ";
		for(int i=outside+1;i<inside;i++)
			cout<<stream[i];
		cout<<endl;
		cout<<"lparenthesis  )"<<endl;
	}
	else if(flag==1)
		cout<<"invalid input";
	system("pause");
	return 0;
}