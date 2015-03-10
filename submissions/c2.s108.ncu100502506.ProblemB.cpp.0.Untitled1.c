#include<iostream>
#include<string>
using namespace std;
string tempstring;
string tempid;
int main()
{
	string temp;
	while(getline(cin,temp))
	{
		for(unsigned int i=0;i<temp.length();i++)
		{
			if(temp[i]==' ')
				temp.erase(temp.begin()+i);
		}
		for(unsigned int i=0;i<temp.length();i++)
		{
			char tempchar=temp[i];
			if(tempchar=='s')
			{
				tempchar=temp[++i];
				//if(tempchar==' ')
				//{
				//tempchar=temp[++i];
				if((((int)tempchar<=(int)'o')&&((int)tempchar>=(int)'a'))||(int)tempchar==(int)'q'||(int)tempchar==(int)'r'||(((int)tempchar<=(int)'z')&&((int)tempchar>='t')))
				{
					tempid=tempchar;
					tempchar=temp[++i];
					//if(tempchar==' ')
					//{
					//tempchar=temp[++i];
					if(tempchar=='\"')
					{
						tempstring="";
						while(1)
						{
							tempchar=temp[++i];
							tempstring=tempstring+tempchar;
							if(tempchar=='\"')
							{

								tempstring=tempstring.substr(0,tempstring.length()-1);
								cout<<"strdcl s\n";
								cout<<"id "<<tempid<<endl;
								cout<<"quote \""<<endl;
								cout<<"string ";
								cout<<tempstring<<endl;
								cout<<"quote \"\n"<<endl;
								break;
							}
						}

					}
					else
					{
						cout<<"valid input\n";
						return 0;
					}
				}
				else
				{
					cout<<"valid input\n";
					return 0;
				}
			}
			else if(tempchar=='p')
			{
				tempchar=temp[++i];
				//if(tempchar==' ')
				//{
				cout<<"print p"<<endl;
				//tempchar=temp[++i];
				if((((int)tempchar<=(int)'o')&&((int)tempchar>=(int)'a'))||(int)tempchar==(int)'q'||(int)tempchar==(int)'r'||(((int)tempchar<=(int)'z')&&((int)tempchar>='t')))
				{
					cout<<"id "<<tempchar<<endl;
				}

				else
				{
					cout<<"valid input\n";
					return 0;
				}
			}
		}

	}
	//system("pause");"
	return 0;
}
//#include<iostream>
//using namespace std;
//int main()
//{
//    char temp;
//    while(cin>>temp)
//	{
//		if((((int)temp<=(int)'o')&&((int)temp>=(int)'a'))||(int)temp==(int)'q'||(int)temp==(int)'r'||(((int)temp<=(int)'z')&&((int)temp>='t')))
//			cout<<(int)temp<<endl;
//	}
//	system("pause");
//    return 0;
//}
