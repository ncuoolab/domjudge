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
    for(int i=0;i<s.length();i++)
    {
        (*count)++;
        if(s[i]>='A'&&s[i]<='Z'||s[i]>='a' &&s[i]<='z'||s[i]=='_')
        {
            if(i==s.length()-1)
            {
                name+=s[i];
                t[*count].content=name;
                t[*count].name="id";
            }
            else
            {
                name+=s[i];
                //t[*count].content=name;
                //t[*count].name="id";
                (*count)--;
            }
        }
        /*else if(s[0]=='a'|| s[0]>='c' &&s[0]<='z')
        {
            for(int i=0;i<s.length();i++)
            {
                name+=s[i];
            }
            t[*count].content=name;
            t[*count].name="LastName";
        }*/
        else if(s[i]<='9'&&s[i]>='0')
        {
            if(i==s.length()-1)
            {
                num+=s[i];
                t[*count].content=num;
                t[*count].name="inum";
            }
            else
            {
                num+=s[i];
                //t[*count].content=num;
                //t[*count].name="inum";
                (*count)--;
            }
        }
        else if(s[i]=='(')
        {
            if(name!="")
            {
                t[*count].content=name;
                t[*count].name="id";
                name="";
                (*count)++;
            }
            else if(num!="")
            {
                t[*count].content=num;
                t[*count].name="inum";
                (*count)++;
                num="";
            }
            t[*count].content="(";
            t[*count].name="lparenthesis";
        }
        else if(s[i]==')')
        {
            if(name!="")
            {
                t[*count].content=name;
                t[*count].name="id";
                (*count)++;
                name="";
            }
            else if(num!="")
            {
                t[*count].content=num;
                t[*count].name="inum";
                (*count)++;
                num="";
            }
            t[*count].content=")";
            t[*count].name="rparenthesis";
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
            break;
        }
    }
        /*if(s[0]=='l')
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

                }
            }
            t[*count].content=num;
            t[*count].name="level";
        }*/
        /*else if(s[0]=='b')
        {
            t[*count].content="b";
            t[*count].name="battle";
        }*/

}

void parser(int*count, token*t)
{
    if((*count)==-1)
    {
        //cout<<"0"<<endl;
        cout<<"invalid input";
        return;
    }
    if(t[1].name!="id")
    {
        //cout<<"1"<<endl;
        cout<<"invalid input";
        return;
    }
    if(t[2].name!="lparenthesis" )
    {
        //cout<<"2"<<endl;
        cout<<"invalid input";
        return;
    }
    if(t[3].name!="id"&&t[3].name!="inum"&&t[3].name!=" ")
    {
        //cout<<"3"<<endl;
        cout<<"invalid input";
        return;
    }
    if(t[4].name!="rparenthesis")
    {
        //cout<<"4"<<endl;
        cout<<"invalid input";
        return;
    }
    /*if(t[5].name!="cid"&&t[5].name!=""&&t[5].name!="FirstName"&&t[5].name!="LastName"&&t[5].name!="")
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
    }*/
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
