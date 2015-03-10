#include<iostream>
#include<string>
using namespace std;
string tempstring;
string tempid;
string output;
int main()
{
	string temp;
	while(getline(cin,temp))
	{
		//output="";
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
								output=output+"strdcl s\n";
								output=output+"id "+tempid+"\n";
								output=output+"quote \"\n";
								output=output+"string ";
								output=output+tempstring+"\n";
								output=output+"quote \"\n";

								//cout<<"strdcl s\n";
								//cout<<"id "<<tempid<<endl;
								//cout<<"quote \""<<endl;
								//cout<<"string ";
								//cout<<tempstring<<endl;
								//cout<<"quote \"\n"<<endl;
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
				output=output+"print p\n";
				//tempchar=temp[++i];
				if((((int)tempchar<=(int)'o')&&((int)tempchar>=(int)'a'))||(int)tempchar==(int)'q'||(int)tempchar==(int)'r'||(((int)tempchar<=(int)'z')&&((int)tempchar>='t')))
				{
					tempchar=temp[++i];

					if(tempchar!=NULL)
					{
						cout<<"valid input\n";
						return 0;
					}
					else

						output=output+"id "+tempchar+"\n";

				}
				else
				{
					cout<<"valid input\n";
					return 0;
				}
			}
		}

	}
	cout<<output;
	//system("pause");
	return 0;
}
