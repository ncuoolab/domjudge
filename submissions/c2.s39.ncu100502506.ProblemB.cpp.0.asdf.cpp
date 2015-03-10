#include<iostream>
#include<string>
using namespace std;
string tempstring;
int main()
{
	string temp;
	while(getline(cin,temp))
	{
		for(unsigned int i=0;i<temp.length();i++)
		{
			char tempchar=temp[i];
			if(tempchar=='s')
			{
				tempchar=temp[++i];
				if(tempchar==' ')
				{
					tempchar=temp[++i];
					if(((tempchar<=111)&&(tempchar>=97))||113||114||((tempchar<=122)&&(tempchar>=116)))
					{

						tempchar=temp[++i];
						if(tempchar==' ')
						{
							tempchar=temp[++i];
							if(tempchar=='\"')
							{
								tempstring="";
								while(true)
								{
									tempchar=temp[++i];
									tempstring=tempstring+tempchar;
									if(tempchar=='\"')
									{
										cout<<"strdcl s\n";
										cout<<"id "<<tempchar<<endl;
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
							}
						}
						else
						{
							cout<<"valid input\n";
						}
					}
					else
					{
						cout<<"valid input\n";
					}
				}
				else
				{
					cout<<"valid input\n";
				}
			}
			else if(tempchar=='p')
			{
				tempchar=temp[++i];
				if(tempchar==' ')
				{
					cout<<"print p"<<endl;
					tempchar=temp[++i];
					if(((tempchar<=111)&&(tempchar>=97))||113||114||((tempchar<=122)&&(tempchar>=116)))
					{
						cout<<"id "<<tempchar<<endl;
					}
				}
				else
				{
					cout<<"valid input\n";
				}
			}
		}
	}
	return 0;
}
