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
        if(!(input[i]>='a'&&input[i]<='z')&&!(input[i]>='A'&&input[i]<='Z')&&!(input[i]>='0'&&input[i]<='9')&&input[i]!='('&&input[i]!=')'&&input[i]!=' ')
        {
            cout<<"invalid input";
            system("pause");
            return 0;
        }

    }
    for(unsigned int i=0;i<input.length();i++)
    {
        a++;
        if((input[i]>='a'&&input[i]<='z')||(input[i]>='A'&&input[i]<='Z'))
        {
            id+=input[i];
            if((input[i+1]>='a'&&input[i+1]<='z')||(input[i+1]>='A'&&input[i+1]<='Z'))
            {
                //do nothing
            }
            else if(input[i+1]>='0'&&input[i+1]<='9')
            {
                cout<<"invalid input";
                system("pause");
                return 0;
            }
            else if((input[i+1]=='('||input[i+1]==')')||input[i+1]==' ')
            {
                cout<<"id "<<id<<endl;
                id="";
            }
            else
            {
                cout<<"id "<<id<<endl;
                id="";
            }
        }
        else if(input[i]>='0'&&input[i]<='9')
        {
            inum+=input[i];
            if(input[i+1]>='0'&&input[i+1]<='9')
            {
                //do nothing
            }
            else if((input[i+1]>='a'&&input[i+1]<='z')||(input[i+1]>='A'&&input[i+1]<='Z'))
            {
                cout<<"invalid input";
                system("pause");
                return 0;
            }
            else if(input[i+1]==' '||input[i+1]==')'||input[i+1]=='(')
            {
                cout<<"inum "<<inum<<endl;
                inum="";
            }
            else
            {
                cout<<"inum "<<inum<<endl;
                inum="";
            }
        }
        else if(input[i]=='(')
        {

            cout<<"lparenthesis ("<<endl;
        }
        else if(input[i]==')')
        {

            cout<<"rparenthesis )"<<endl;
        }
    }
    system("pause");
    return 0;
}
//a 'a' z 'z' ( '(' ) ')' 1 49 A 'A'
//
