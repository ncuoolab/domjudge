#include<iostream>
#include<string>
using namespace std;
int main()
{
	string temp;
	while(getline(cin,temp))
	{
		for(unsigned int i=0;i<temp.length();i++)
		{
			if(temp[i]==' '||temp[i]=='\n')
				temp.erase(temp.begin()+i);
		}
		for(int i=0;i<temp.length();i++)
		{
			string tempid="";
			string tempival="";
			if((((int)temp[i]<=90)&&(int)temp[i]>=65)||(((int)temp[i]<=122)&&(int)temp[i]>=97)||(((int)temp[i])==95))
			{
				tempid=tempid+temp[i];
				i++;
				while((((int)temp[i]<=90)&&(int)temp[i]>=65)||(((int)temp[i]<=122)&&(int)temp[i]>=97)||(((int)temp[i])==95)||(((int)temp[i])==40))
				{
					//cout<<tempid;
					if((int)temp[i]==40)
					{
						i++;
						while((((int)temp[i]>=48)&&(int)temp[i]<=57)||((int)temp[i]==41))
						{
							if((int)temp[i]==41)
							{
								cout<<"id "<<tempid<<endl;
								cout<<"lparenthesis (\n";
								cout<<"inum "<<tempival<<endl;
								cout<<"rparenthesis )";
								//system("pause");
								return 0;
							}
							tempival=tempival+temp[i];
							i++;
						}
						string tempid2="";
						while((((int)temp[i]<=90)&&(int)temp[i]>=65)||(((int)temp[i]<=122)&&(int)temp[i]>=97)||(((int)temp[i])==95)||((int)temp[i]==41))
						{
							if((int)temp[i]==41)
							{
								cout<<"id "<<tempid<<endl;
								cout<<"lparenthesis (\n";
								cout<<"id "<<tempid2<<endl;
								cout<<"rparenthesis )";
								//system("pause");
								return 0;
							}
							tempid2=tempid2+temp[i];
							i++;
						}
						cout<<"invalid input";
						return 0;
					}
					tempid=tempid+temp[i];
					i++;
				}
				cout<<"invalid input";
				return 0;
			}
			else
			{
				cout<<"invalid input";
				return 0;
			}
		}
	}
	//system("pause");
	return 0;
}