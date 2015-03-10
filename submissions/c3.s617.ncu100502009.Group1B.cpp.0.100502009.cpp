#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

class  token
{
public:
    token()
    {

    }
    string name;
    string content;
};

void scanner(string s,int* count,token*t)
{
    string num="";
    string name="";
    /*for(int i=0;i<s.length();i++)
    {cout<<"invalid input";
        return;

    }*/
    (*count)++;
        if(s[0]=='l')
        {
            num+="l";
            for(int i=1;i<s.length();i++)
            {
                if(s[i]>='0'&&s[i]<='9')
                {
                    num+=s[i];
                }
                else
                {
                    num="";
                    break;
                }
                /*else if(s[i]=='a'|| s[i]>='c' &&s[i]<='z')
                {

                }*/
            }
            t[*count].content=num;
            t[*count].name="level";
        }
        else if(s[0]=='b')
        {
            t[*count].content="b";
            t[*count].name="battle";
        }
        else if(s[0]>='A'&&s[0]<='Z')
        {
            name+=s[0];
            if(s.length()>1)
            {
                for(int i=1;i<s.length();i++)
                {
                    if(s[i]>='a'&&s[i]<='z')
                    {
                        name+=s[i];
                    }
                }
            }
            t[*count].content=name;
            t[*count].name="FirstName";
        }
        else if(s[0]=='a'|| s[0]>='c' &&s[0]<='z')
        {
            for(int i=0;i<s.length();i++)
            {
                name+=s[i];
            }
            t[*count].content=name;
            t[*count].name="LastName";
        }
        else if(s[0]<='9'&&s[0]>='0')
        {
            for(int i=0;i<s.length();i++)
            {
                num+=s[i];
            }
            t[*count].content=num;
            t[*count].name="cid";
        }
        else
        {
            /*for(int i=0;i<s.length();i++)
            {
                name+=s[i];
            }
            t[*count].content=name;
            t[*count].name="false";*/
            (*count)=-1;
        }
}

void parser(int*count, token*t)
{
    if((*count)==-1)
    {
        //cout<<"1"<<endl;
        cout<<"invalid input";
        return;
    }
    if(t[1].name!="level")
    {
        //cout<<"1"<<endl;
        cout<<"invalid input";
        return;
    }
    if(t[2].name!="cid" && t[2].name!="FirstName")
    {
        //cout<<"2"<<endl;
        cout<<"invalid input";
        return;
    }
    if(t[3].name!="LastName"&&t[3].name!="battle"&&t[3].name!="")
    {
        //cout<<"3"<<endl;
        cout<<"invalid input";
        return;
    }
    if(t[4].name!="cid"&&t[4].name!="battle"&&t[4].name!="FirstName"&&t[4].name!="")
    {
        //cout<<"4"<<endl;
        cout<<"invalid input";
        return;
    }
    if(t[5].name!="cid"&&t[5].name!=""&&t[5].name!="FirstName"&&t[5].name!="LastName"&&t[5].name!="")
    {
        //cout<<"5"<<endl;
        cout<<"invalid input";
        return;
    }
    if(t[6].name!="LastName"&&t[6].name!="")
    {
        //cout<<"6"<<endl;
        cout<<"invalid input";
        return;
    }
    for(int i=1;i<=(*count);i++)
    {
        cout<<t[i].name<<" "<<t[i].content;
        if(i<(*count))
        {
            cout<<endl;
        }
    }
}

int main()
{
    token t[100];
    int count=0;
    string input;
    while(cin>>input)
    {
        //cout<<input<<".";
        scanner(input,&count,t);
    }
    /*for(int i=1;i<=count;i++)
    {
        cout<<t[i].name<<endl;
    }*/
    parser(&count,t);
    system("pause");
    return 0;
}
