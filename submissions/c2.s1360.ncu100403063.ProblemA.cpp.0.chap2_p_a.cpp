#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;
int r=0;
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
        if(s[i]>='a' && s[i]<='z')
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
                (*count)--;
            }
        }
        else if(s[i]>='0' && s[i]<='9')
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
                (*count)--;
            }
        }
        else if(s[i]=='=')
        {
            if(i==s.length()-1)
            {
                num+=s[i];
                t[*count].content='=';
                t[*count].name="assign";
            }
            else
            {
                num+=s[i];
                (*count)--;
            }
        }
        /*else if(s[i]=='(')
        {
            r++;
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
            r++;
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
        }*/

        else
        {
            (*count)=-1;
            break;
        }
    }
}

void parser(int*count, token*t)
{
    if((*count)==-1)
    {
        cout<<"invalid input";
        return;
    }
    if(t[1].name!="id")
    {
        cout<<"invalid input";
        return;
    }
    /*if(t[2].name!="lparenthesis" )
    {
        cout<<"invalid input";
        return;
    }*/
    if(t[3].name!="id" && t[3].name!="inum" && t[3].name!="")
    {
        cout<<"invalid input";
        return;
    }
    if(/*t[4].name!="rparenthesis"&&*/t[4].name!="")
    {
        cout<<"invalid input";
        return;
    }
    if(t[5].name!="")
    {
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
        scanner(input,&count,t);
    }
    parser(&count,t);
    system("pause");
    return 0;
}
