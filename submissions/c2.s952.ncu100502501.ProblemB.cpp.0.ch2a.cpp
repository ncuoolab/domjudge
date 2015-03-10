#include<iostream>
#include<string>
#include<cstdlib>
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
			if(temp[i]==' '||temp[i]=='\n'||temp[i]=='\r')
				temp.erase(temp.begin()+i);
		}

		//cout<<temp;
		//system("pause");
		for(int i=0;i<temp.length();i++)
		{
			string tempid="",tempid2="";
			string tempstr="";
			string tempival="";
			if((int)temp[i]==115){ //strdcl s
                i++;
                if((temp[i]>=97&&temp[i]<=111)||(temp[i]==113)||(temp[i]==114)||(temp[i]>=116&&temp[i]<=122)){//id
                    tempid=temp[i];
                    i++;
                    if(temp[i]=='\"'){ //"
                        i++;
                        if((temp[i]>=97&&temp[i]<=122)||(temp[i]>=65&&temp[i]<=90)||(temp[i]>=48&&temp[i]<=57)){ //AZaz09
                            while((temp[i]>=97&&temp[i]<=122)||(temp[i]>=65&&temp[i]<=90)||(temp[i]>=48&&temp[i]<=57)){ //AZaz09
                                tempstr=tempstr+temp[i];
                                i++;
                            }
                            if(temp[i]=='\"'){
                                i++;
                                if(temp[i]==112&&(temp[i+1]>=97&&temp[i+1]<=111)||(temp[i+1]==113)||(temp[i+1]==114)||(temp[i+1]>=116&&temp[i+1]<=122)){ //p
                                    i++;
                                    tempid2=temp[i];
                                    cout<<"strdcl s"<<endl;
                                    cout<<"id "<<tempid<<endl;
                                    cout<<"quote \""<<endl;
                                    cout<<"string "<<tempstr<<endl;
                                    cout<<"quote \""<<endl;
                                    cout<<"print p"<<endl;
                                    cout<<"id "<<tempid2<<endl;
                                    system("pause");
                                    return 0;
                                }
                                cout<<"invalid input";
                                return 0;
                            }
                            cout<<"invalid input";
                            return 0;
                        }
                        cout<<"invalid input";
						return 0;
                    }
                    cout<<"invalid input";
                    return 0;
                }
                cout<<"invalid input";
                return 0;
			}
			else{
                cout<<"invalid input";
                return 0;
			}
		}
			/*if((((int)temp[i]<=90)&&(int)temp[i]>=65)||(((int)temp[i]<=122)&&(int)temp[i]>=97)||(((int)temp[i])==95))
			{
				tempid=tempid+temp[i];
				i++;
				while((((int)temp[i]<=90)&&(int)temp[i]>=65)||(((int)temp[i]<=122)&&(int)temp[i]>=97)||(((int)temp[i])==95)||(((int)temp[i])==40))
				{
					//cout<<tempid;
					if((int)temp[i]==40)
					{
						string tempid2="";
						i++;
						if((tempival.length()==0)&&(tempid2.length()==0)&&((int)temp[i]==41))
						{
							if((int)temp[i]==41)
							{
								cout<<"id "<<tempid<<endl;
								cout<<"lparenthesis (\n";
								cout<<"rparenthesis )";
								//system("pause");
								return 0;
							}
						}
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
		}*/

	system("pause");
	return 0;
}
