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
        if(number!=2)
        {
            cout<<"invalid input"<<endl;
            exit(0);
        }
    }
    else if(grammarcount==2)
    {
        if(number==3)
        {
            cout<<output<<endl;
            exit(0);
        }
        else if(number!=1&&number!=2)
        {
            cout<<"invalid input"<<endl;
            exit(0);
        }
    }
    else if(grammarcount==3)
    {
        if(number!=3)
        {
            cout<<"invalid input"<<endl;
            exit(0);
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
    while(cin>>input1)
    {
        hold=hold+input1;
    }
    //cout<<hold<<endl;
    length=hold.size();
    while(item<=length)
    {
        while((hold[item]>=97&&hold[item]<=122)||(hold[item]>=65&&hold[item]<=90)||hold[item]=='_')
        {
            //cout<<"AAA: "<<hold[item]<<endl;
            regit=regit+hold[item];
            if((hold[item+1]>=97&&hold[item+1]<=122)||(hold[item+1]>=65&&hold[item+1]<=90)||hold[item+1]=='_')
            {
                item++;
            }
            else
            {
                output=output+"id "+regit+"\n";
                regit="";
                judgeIfGrammar(0);
                break;
            }
        }
        while(hold[item]>=48&&hold[item]<=57)
        {
            //cout<<"BBB: "<<hold[item]<<endl;
            regit=regit+hold[item];
            if(hold[item+1]>=48&&hold[item+1]<=57)
            {
                item++;
            }
            else
            {
                output=output+"inum "+regit+"\n";
                regit="";
                judgeIfGrammar(1);
                break;
            }
        }
        if(hold[item]=='(')
        {
            output=output+"Iparenthesis "+hold[item]+"\n";
            judgeIfGrammar(2);
        }
        if(hold[item]==')')
        {
            output=output+"rparenthesis "+hold[item]+"\n";
            judgeIfGrammar(3);
        }
        item++;
    }
    cout<<output<<endl;

    system("pause");
    return 0;
}
