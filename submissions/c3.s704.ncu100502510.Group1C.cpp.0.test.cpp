#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
    string temp;
    string input="";
    getline(cin,input);
    string id="";
    string inum="";
    int a=0;
    for(unsigned int i=0;i<input.length();i++)
    {
        if(!(input[i]>='a'&&input[i]<=122)&&!(input[i]>=65&&input[i]<=90)&&!(input[i]>=48&&input[i]<=57)&&input[i]!=40&&input[i]!=41&&input[i]!=32)
        {
            cout<<"invalid input";
            system("pause");
            return 0;
        }

    }
    for(unsigned int i=0;i<input.length();i++)
    {
        a++;
        if((input[i]>='a'&&input[i]<=122)||(input[i]>=65&&input[i]<=90))
        {
            id+=input[i];
            if((input[i+1]>='a'&&input[i+1]<=122)||(input[i+1]>=65&&input[i+1]<=90))
            {
                //do nothing
            }
            else if(input[i+1]>=48&&input[i+1]<=57)
            {
                cout<<"invalid input";
                system("pause");
                return 0;
            }
            else if((input[i+1]==40||input[i+1]==41)||input[i+1]==32||input[i-1]==32)
            {
                cout<<"id "<<id<<endl;
                id="";
            }
        }
        else if(input[i]>=48&&input[i]<=57)
        {
            inum+=input[i];
            if(input[i+1]>=48&&input[i+1]<=57)
            {
                //do nothing
            }
            else if((input[i+1]>='a'&&input[i+1]<=122)||(input[i+1]>=65&&input[i+1]<=90))
            {
                cout<<"invalid input";
                system("pause");
                return 0;
            }
            else if(input[i+1]==32||input[i-1]==32||input[i-1]==40||input[i+1]==41)
            {
                cout<<"inum "<<inum<<endl;
                inum="";
            }
        }
        else if(input[i]==40)
        {

            cout<<"lparenthesis ("<<endl;
        }
        else if(input[i]==41)
        {

            cout<<"rparenthesis )"<<endl;
        }
    }
    system("pause");
    return 0;
}
//a 'a' z 122 ( 40 ) 41 1 49 A 65
//
