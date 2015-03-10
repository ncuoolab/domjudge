#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

void check(string arr[],string arr1[],int index)
{
    int i=0;


    if(arr[i]=="strdcl")
    {
        if(arr[i+1]=="id" && arr[i+2]=="quote" && arr[i+3]=="string" && arr[i+4]=="quote" && arr[i+5]=="print" && arr[i+6]=="id" )
        {
            i+=7;
            for(int j=0;j<index;j++)
            {
                cout << arr[j] << arr1[j] << endl;
            }
            cout <<"true1" <<endl;
        }
        else
            cout << "valid input1" << endl;

    }
    else
    {
        cout << "valid input99" << endl;;
    }
}

int main()
{
	string str1;
	string outputstr;
	string arr[9999];
	string arr1[9999];
    int index=0;
	for(int i=0;i<5;i++)
	{
		cin >> str1;
		if(str1=="s")
		{
			//cout << "strdcl " + str1 + " " << endl;
			arr[index]="strdcl ";
			arr1[index]=str1;
			index++;
		}
		else if(str1.size()==1 && str1!="s" && str1!="p"  )
		{
			//cout << "id " + str1 + " " << endl;
			arr[index]="id ";
			arr1[index]=str1;
			index++;
		}
		else if(str1=="p")
		{
			//cout << "print " + str1 + " " << endl;
			arr[index]="print ";
			arr1[index]=str1;
			arr[index+2]="$";
			index++;
		}
		else if(str1[0]=='\"')
		{
			//cout << "quote " << str1[0] << " " << endl;
			arr[index]="quote ";
			arr1[index]=str1[0];
			index++;
			arr1[index]=str1.substr(1,str1.size()-2);
			for(int i=1;i<str1.size()-1;i++)
			{
				if(i==1)
				{
					//cout << "string ";
					arr[index]="string ";
					//arr[index]=str1;
					index++;
				}
                else if(i>1)
                {
                    ;
                }

                //cout << str1[i] ;
				if(i==str1.size()-2)
				{
					cout << " " << endl;
				}
			}
			//cout << "quote " << str1[str1.size()-1] << endl;
			arr[index]="quote ";
			arr1[index]=str1[0];
			index++;
		}
        if(i==4)
        {
            cout << index << endl;
            for(int i=0;i<index;i++)
            {
                cout << arr[i] << endl;
            }
            check(arr,arr1,index);
        }
	}


	system("pause");
	return 0;
}

