#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;
int main()
{
	char token;
	string str="";
	string stream="";
	int flag=0,count=0;
	int flag_assi=0;
	getline(cin,str);
	for(int i=0;i<str.length();i++)
	{
		
		if(str[i]-' '==0)
		{	
			;
		}		
		else if(flag_assi==0&&str[i]-'a'>=0&&str[i]-'z'<=0)
		{
			stream=stream+str[i];
			count++;
		}
		else if(flag_assi==0&&str[i]-'='==0)
		{
			stream=stream+str[i];
			flag_assi=1;
		}
		else if(flag_assi==0&&str[i]-'='!=0)
		{
			//cout<<"valid input2"<<str[i]<<i;
			flag=1;
			break;
		}
		else if(flag_assi==1&&str[i]-'0'>=0&&str[i]-'9'<=0)
		{	
			stream=stream+str[i];
		}
		else if(flag_assi==1&&str[i]-'0'<0||str[i]-'9'>0)
		{	
			//cout<<"valid input4";
			flag=1;
			break;
		}
		//cout<<i;
	}
	if(flag==0)
	{
		cout<<"id "<<stream[0]<<endl;
		cout<<"assign "<<stream[1]<<endl;
		cout<<"inum ";
		for(int i=2;i<stream.length();i++)
			cout<<stream[i];
	}
	else
		cout<<"valid input";
	system("pause");
	return 0;
}