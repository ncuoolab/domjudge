#include<iostream>
#include<cstdlib>

using namespace std;

int grammarcount=0;
bool flag=false;
string output="";

void judgeIfGrammar(int number)
{
    if(grammarcount==0)
    {
        if(number!=0)
        {
            cout<<"invalid input"<<endl;
            exit(0);
        }
    }
    else if(grammarcount==1)
    {
        if(number!=3&&number!=1)
        {
            cout<<"invalid input"<<endl;
            exit(0);
        }
        else
        {
            if(number==1)
            {
                flag=true;
            }
            else
            {
                flag=false;
            }
        }
    }
    else if(grammarcount==2)
    {
        if(flag)
        {
            if(number!=2)
            {
                cout<<"invalid input"<<endl;
                exit(0);
            }
        }
        else
        {
            if(number!=4)
            {
                cout<<"invalid input"<<endl;
                exit(0);
            }
        }
    }
    else if(grammarcount==3)
    {
        if(flag)
        {
            if(number!=4)
            {
                cout<<"invalid input"<<endl;
                exit(0);
            }
        }
        else
        {
            if(number!=3&&number!=1)
            {
                cout<<"invalid input"<<endl;
                exit(0);
            }
        }
    }
    else if(grammarcount==4)
    {
        if(flag)
        {
            if(number!=3&&number!=1)
            {
                cout<<"invalid input"<<endl;
                exit(0);
            }
        }
        else
        {
            if(number!=2)
            {
                cout<<"invalid input"<<endl;
                exit(0);
            }
        }
    }
    else if(grammarcount==4)
    {
        if(flag)
        {
            if(number!=2)
            {
                cout<<"invalid input"<<endl;
                exit(0);
            }
        }
    }
    grammarcount++;
}
int main()
{
    int item=0;
    int length;
    string input1;
    string hold="";
    string regit="";
    while(getline(cin,input1))
    {
        hold=hold+input1;
    }
    length=hold.size();
    while(item<=length)
    {
        if(hold[item]=='l')
        {
            regit=regit+hold[item];
            if(hold[item+1]>=48&&hold[item+1]<=57)
            {
                item++;
                regit=regit+hold[item];
                while(hold[item+1]>=48&&hold[item+1]<=57)
                {
                    item++;
                    regit=regit+hold[item];
                }
                output=output+"level "+regit+"\n";
                regit="";
                judgeIfGrammar(0);
                item++;
            }
            else
            {
                while(hold[item+1]==97||(hold[item+1]>=99&&hold[item+1]<=122))
                {
                    item++;
                    regit=regit+hold[item];
                }
                output=output+"LastName "+regit+"\n";
                regit="";
                judgeIfGrammar(2);
            }
        }
        if(hold[item]>=65&&hold[item]<=90)
        {
            regit=regit+hold[item];
            while(hold[item+1]>=97&&hold[item+1]<=122)
            {
                item++;
                regit=regit+hold[item];
            }
            output=output+"FirstName "+regit+"\n";
            regit="";
            judgeIfGrammar(1);
            item++;
        }
        while(hold[item]==97||(hold[item]>=99&&hold[item]<=122))
        {
            regit=regit+hold[item];
            if(hold[item+1]==97||(hold[item+1]>=99&&hold[item+1]<=122))
            {
                item++;
            }
            else
            {
                output=output+"LastName "+regit+"\n";
                regit="";
                judgeIfGrammar(2);
                break;
            }
        }
        while(hold[item]>=48&&hold[item]<=57)
        {
            regit=regit+hold[item];
            if(hold[item+1]>=48&&hold[item+1]<=57)
            {
                item++;
            }
            else
            {
                output=output+"cid "+regit+"\n";
                regit="";
                judgeIfGrammar(3);
                break;
            }
        }
        if(hold[item]==98)
        {
            output=output+"battle "+hold[item]+"\n";
            judgeIfGrammar(4);
        }
        item++;
    }
    cout<<output<<endl;

    system("pause");
    return 0;
}
