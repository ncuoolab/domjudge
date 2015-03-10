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
        if(str[i]>='a' && str[i]<='z')
        {
            n[*count].content=str[i];
            n[*count].name="id";
        }
        else if(str[i]=='=')
        {
            n[*count].content=str[i];
            n[*count].name="assign";
        }
        else if(str[i]=='.')
        {
            n[*count].content=num;
            n[*count].name="inum";
            num="";
        }
        else if(num!="" && i==str.length()-1)
        {
            num+=str[i];
            n[*count].content=num;
            n[*count].name="inum";
        }
        else if(str[i]>='0' && str[i]<='9')
        {
            num+=str[i];
            (*count)--;
        }
        (*count)++;
    }
}

void parser(node* n)
{
    if(n[0].name !="id")
    {
        cout<<"invalid input";
        return;
    }
    if(n[1].name !="assign")
    {
        cout<<"invalid input";
        return;
    }
    if(n[2].name !="id" && n[2].name !="inum")
    {
        cout<<"invalid input";
        return;
    }
    if(n[3].name !="")
    {
        cout<<"valid input";
        return;
    }
    cout<<n[0].name<<" "<<n[0].content<<endl;
    cout<<n[1].name<<" "<<n[1].content<<endl;
    cout<<n[2].name<<" "<<n[2].content;
}

int main()
{
    string str;
    node n[20];
    int count=0;
    while(cin>>str)
    {
        scanner(str,&count,n);
    }
    parser(n);
    system("pause");
    return 0;
}
