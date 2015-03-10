#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;
int main()
{
	int flag=1;
	int num=2;
	string input,stream,temp,inputORI;
	int l=0,r=0;
	int outside,inside;

	getline(cin,inputORI);
	for(int i=0;i<inputORI.length();i++)
	{
		while(inputORI[i]-' '==0)
			i++;
		input=input+inputORI[i];
	}
	for(int i=0;i<input.length();i++)
	{
		if(input[i]-' '==0);
		else if(l==0&&((input[i]-'a'>=0&&input[i]-'z'<=0)||(input[i]-'A'>=0&&input[i]-'Z'<=0)||input[i]-'_'==0))
		{
			stream=stream+input[i];
		}
		else if(input[i]-'('==0)
		{
			stream=stream+input[i];
			outside=i;
			l=1;
		}
		else if(l==1&&((input[i]-'a'>=0&&input[i]-'z'<=0)||(input[i]-'A'>=0&&input[i]-'Z'<=0)||input[i]-'_'==0))
		{
			
			if(num==1)
			{
				flag==1;
				break;
			}
			num=0;
			stream=stream+input[i];
		}
		else if(l==1&&(input[i]-'0'>=0&&input[i]-'9'<=0))
		{
			
			if(num==0)
			{
				flag==1;
				break;
			}
			num=1;
			stream=stream+input[i];
		}
		else if(input[i]-')'==0)
		{
			inside=i;
			stream=stream+input[i];
			flag = 0;
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
		if((inside-outside)!=1)
		{
			if(num==1)
				cout<<"inum ";
			else
				cout<<"id ";
		
		for(int i=outside+1;i<inside;i++)
			cout<<stream[i];
		cout<<endl;
		}
		cout<<"rparenthesis  )";
	}
	else if(flag!=0)
		cout<<"invalid input";
	system("pause");
	return 0;
}