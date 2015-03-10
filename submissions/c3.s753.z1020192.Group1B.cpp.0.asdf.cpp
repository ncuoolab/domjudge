#include<iostream>
#include<string>
using namespace std;
int main()
{
	string tempshort;
	string temp;
	while(getline(cin,tempshort))
	{
		temp=temp+tempshort;
		if(tempshort==")")
			break;
	}
		for(unsigned int i=0;i<temp.length();i++)
		{
			if(temp[i]=='\n'||temp[i]=='\r')
				temp.erase(temp.begin()+i);
		}

		//cout<<temp;
		//system("pause");
		for(int i=0;i<temp.length();i++)
		{
			if(temp[i]=='l')
			{
				i++;
				string tempival="";
				string firstname="";
				string lastname="";
				string firstname2="";
				string lastname2="";
				string tempival2="";
				while(((int)temp[i]>='0')&&((int)temp[i]<='9'))
				{
					//cout<<tempival;
					//system("pause");
					tempival=tempival+temp[i];
					i++;
					if(temp[i]==' ')
					{
						i++;
						if(((int)temp[i]>=65)&&((int)temp[i]<=90))
						{
							firstname=firstname+temp[i];
							i++;
							while((((int)temp[i]>=97)&&((int)temp[i]<=122))||temp[i]==' ')
							{
								if(temp[i]==' ')
								{
									i++;
									while((((int)temp[i]>=97)&&((int)temp[i]<=122)))
									{
										if(temp[i]=='b')
										{
											i=i+2;
											//cout<<(int)temp[i];
											////cout<<temp.length();
											//system("pause");
											if((((int)temp[i]>=65)&&((int)temp[i]<=90)))//id
											{
												firstname2=firstname2+temp[i];
												i++;
												while((((int)temp[i]>=97)&&((int)temp[i]<=122))||temp[i]==' ')
												{
													if(temp[i]==' ')
													{
														i++;
														while((((int)temp[i]>=97)&&((int)temp[i]<=122)))
														{
															lastname2=lastname2+temp[i];
															i++;
															if(i==temp.length())
															{
																cout<<"Level l"<<tempival<<endl;
																cout<<"FirstName "<<firstname<<endl;
																cout<<"LastName "<<lastname<<endl;
																cout<<"battle b"<<endl;
																cout<<"FirstName "<<firstname2<<endl;
																cout<<"LastName "<<lastname2<<endl;
																return 0;
															}
														}
													}
													firstname2=firstname2+temp[i];
													i++;
												}
											}
											else if(((int)temp[i]>='0')&&((int)temp[i]<='9'))//value
											{
												cout<<"fasd";
												system("pause");
												while(((int)temp[i]>='0')&&((int)temp[i]<='9'))
												{
													if(i>temp.length())
													{
														cout<<"Level l"<<tempival<<endl;
														cout<<"FirstName "<<firstname<<endl;
														cout<<"LastName "<<lastname<<endl;
														cout<<"battle b"<<endl;
														cout<<"cid "<<tempival2<<endl;

													}
													tempival2=tempival2+temp[i];
													i++;
												}
											}
											else
											{
												system("pause");
												cout<<"invalid input";
												system("pause");
												break;
											}
										}
										lastname=lastname+temp[i];
										i++;
									}
								}
								firstname=firstname+temp[i];
								i++;
							}
						}	
					}
				}
				cout<<"invalid input";
				break;
			}
			else
			{
				cout<<"invalid input";
				break;
			}
		}
	system("pause");
	return 0;
}