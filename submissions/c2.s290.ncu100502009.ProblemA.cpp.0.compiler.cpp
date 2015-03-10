#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class node
{
public:
    node()
    {
        name="";
        content="";
    }
    string name;
    string content;
};

void scanner(string str,int* count,node* n)
{
    string num="";
    for(int i=0;i<str.length();i++)
    {
        (*count)++;
        if(str[i]>='0' && str[i]<='9')
        {
            if(i==str.length()-1)
            {
                num+=str[i];
                n[*count].content=num;
                n[*count].name="inum";
            }
            else
            {
                num+=str[i];
                (*count)--;
            }

        }
        else if(i==str.length()-1)
        {
            if(num!="")
            {
                n[*count].content=num;
                n[*count].name="inum";
                (*count)++;
            }
        }
        if(str[i]=='.')
        {
            n[*count].content=num;
            n[*count].name="inum";
            num="";
        }
        else if(str[i]>='a' && str[i]<='z')
        {
            n[*count].content=str[i];
            n[*count].name="id";
        }
        else if(str[i]=='=')
        {
            n[*count].content=str[i];
            n[*count].name="assign";
        }

        /*if(num!="")
        {
            n[*count].content=num;
            n[*count].name="inum";
            (*count)++;
        }
        /*else if(str[i]>='0' && str[i]<='9')
        {
            num+=str[i];
            (*count)--;
        }*/
        /*else if(num!="" || i==str.length()-1)
        {
            n[*count].content=num;
            n[*count].name="inum";
        }*/

    }
    //cout<<*count<<endl;
}

void parser(node* n)
{
    if(n[1].name !="id")
    {
        cout<<"valid input";
        //cout<<1;
        return;
    }
    if(n[2].name !="assign")
    {
        cout<<"valid input";
        //cout<<2;
        return;
    }
    if(n[3].name !="id" && n[3].name !="inum")
    {
        cout<<"valid input";
        //cout<<3;
        return;
    }
    if(n[4].name !="")
    {
        cout<<"valid input";
        //cout<<4;
        return;
    }
    cout<<n[1].name<<" "<<n[1].content<<endl;
    cout<<n[2].name<<" "<<n[2].content<<endl;
    cout<<n[3].name<<" "<<n[3].content;
}

int main()
{
    string str;
    node n[100];
    int count=0;
    //getline(cin,n,'\n');
    while(cin>>str)
    {
        //cout<<str;
        scanner(str,&count,n);
    }
    //cout<<n[1].content;
    /*for(int i =0;i<=count;i++)
    {
        cout<<n[i].name;
    }*/
    parser(n);
    system("pause");
    return 0;
}
