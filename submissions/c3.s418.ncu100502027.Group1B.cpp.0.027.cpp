#include<iostream>
#include<string>
using namespace std;

void terminal(string target)
{
    int noresult=1;
    if(target[0]=='l')
    {
        int Nonumber=0;
        for(int t=1; t<target.length(); t++)
        {
            if((target[t]-'0')<0||(target[t]-'0')>9)
            {
                Nonumber=1;
            }
        }
        if(Nonumber==0)
        {
            cout<<"level "<<target<<endl;
            noresult=0;
        }
    }
    if(noresult==1)
    {
        if((target[0]-'A')>=0&&(target[0]-'A')<=25)
        {

            int Noletter=0;
            for(int t=1; t<target.length(); t++)
            {
                if((target[t]-'A')<0||(target[t]-'A')>57)
                {
                    Noletter=1;
                }
            }
            if(Noletter==0)
            {
                cout<<"FirstName "<<target<<endl;
                noresult=0;
            }
        }
    }
    if(noresult==1)
    {
        if((target[0]-'a')>=0&&(target[0]-'a')<=25&&target[0]!='b')
        {
            int Noletter=0;
            for(int t=1; t<target.length(); t++)
            {
                if((target[t]-'a')<0||(target[t]-'a')>26)
                {
                    Noletter=1;
                }
            }
            if(Noletter==0)
            {
                cout<<"LastName "<<target<<endl;
                noresult=0;
            }
        }
    }
    if(noresult==1)
    {
        if((target[0]-'0')>=0&&(target[0]-'0')<=9)
        {
            int Nonumber=0;
            for(int t=1; t<target.length(); t++)
            {
                if((target[t]-'0')<0||(target[t]-'0')>9)
                {
                    Nonumber=0;
                }
            }
            if(Nonumber==0)
            {
                cout<<"cid "<<target<<endl;
                noresult=0;
            }
        }
    }
    if(noresult==1)
    {
        if(target[0]=='b'&&target.length()==1)
        {
            cout<<"battle "<<target<<endl;
            noresult=0;
        }
    }
    if(noresult==1)
    {
        cout<<"invalid input"<<endl;
    }
}

int main()
{
    string target;
    while(cin>>target){
    //cin>>target;
    terminal(target);}


    return 0;
}
