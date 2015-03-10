#include<iostream>
#include<string>
using namespace std;
int doerror=0,numbers=0;
string result[6]= {};

void doLastName(string LastName)
{
    if((LastName[0]-'a')>=0&&(LastName[0]-'a')<=25&&LastName[0]!='b')
    {
        int Noletter=0;
        for(int t=1; t<LastName.length(); t++)
        {
            if((LastName[t]-'a')<0||(LastName[t]-'a')>26)
            {
                Noletter=1;
            }
        }
        if(Noletter==0)
        {
            result[numbers]="LastName "+LastName;
            numbers++;
        }
        else
        {
            doerror=1;
        }
    }
    else
    {
        doerror=1;
    }

}
void doFirstName(string FirstName)
{
    if((FirstName[0]-'A')>=0&&(FirstName[0]-'A')<=25)
    {

        int Noletter=0;
        for(int t=1; t<FirstName.length(); t++)
        {
            if((FirstName[t]-'A')<0||(FirstName[t]-'A')>57)
            {
                Noletter=1;
            }
        }
        if(Noletter==0)
        {
            result[numbers]="FirstName "+FirstName;
            numbers++;
        }
        else
        {
            doerror=1;
        }
    }
    else
    {
        doerror=1;
    }
}

void docid(string cid)
{
    if((cid[0]-'0')>=0&&(cid[0]-'0')<=9)
    {
        int Nonumber=0;
        for(int t=1; t<cid.length(); t++)
        {
            if((cid[t]-'0')<0||(cid[t]-'0')>9)
            {
                Nonumber=0;
            }
        }
        if(Nonumber==0)
        {
            result[numbers]="cid "+cid;
            numbers++;
        }
        else
        {
            doerror=1;
        }
    }
    else
    {
        doerror=1;
    }
}

void doid(string id)
{
    string cid="",FirstName="",LastName="";
    int twostr=0;
    for(int t=0; t<id.length(); t++)
    {
        if(id[t]==' ')
        {
            twostr++;
        }
    }
    if(twostr==0)
    {
        cid=id;
        docid(cid);
    }
    else
    {
        int goswich=0;
        for(int t=0,s=0; t<id.length(); t++)
        {

            if(goswich==0)
            {
                if(id[t]!=' ')
                {
                    FirstName+=id[t];
                    s++;
                }
                else
                {
                    s=0;
                    goswich=1;
                }

            }
            else
            {
                LastName+=id[t];
                s++;
            }
        }
        doFirstName(FirstName);
        doLastName(LastName);
    }

}

void dobattle(string battle)
{
    if(battle=="b")
    {
        result[numbers]="battle "+battle;
        numbers++;
    }
    else
    {
        doerror=1;
    }
}
void dolevel(string level)
{
    if(level[0]=='l')
    {
        int Nonumber=0;
        for(int t=1; t<level.length(); t++)
        {
            if((level[t]-'0')<0||(level[t]-'0')>9)
            {
                Nonumber=1;
            }
        }
        if(Nonumber==0)
        {
            result[numbers]="level "+level;
            numbers++;
        }
        else
        {
            doerror=1;
        }
    }
    else
    {
        doerror=1;
    }
}

void doStmt(string Stmt)
{
    string battle="",id="";
    int goswich=0;

    for(int t=0; t<Stmt.length(); t++)
    {

        if(goswich==0)
        {
            if(Stmt[t]!=' ')
            {
                battle+=Stmt[t];
            }
            else
            {
                goswich=1;
            }

        }
        else
        {
            id+=Stmt[t];
        }
    }
    dobattle(battle);
    doid(id);
}
void doDcl(string Dcl)
{
    string level="",id="";
    int goswich=0;

    for(int t=0,s=0; t<Dcl.length(); t++)
    {

        if(goswich==0)
        {
            if(Dcl[t]!=' ')
            {
                level+=Dcl[t];
            }
            else
            {
                goswich=1;
            }
        }
        else
        {
            id+=Dcl[t];
        }
    }
    dolevel(level);
    doid(id);
}

int main()
{
    string Proc,Dcl="",Stmt="";
    getline(cin,Proc);

    int sation=0;
    for(int t=0; t<Proc.length(); t++)
    {
        if(Proc[t]==' '&&Proc[t+1]=='b'){
            sation=t;
        }
    }
    for(int t=0; t<Proc.length(); t++)
    {
        if(t<sation)
        {
            Dcl+=Proc[t];
        }
        else if(t>sation)
        {
            Stmt+=Proc[t];
        }

    }

    doDcl(Dcl);
    doStmt(Stmt);

    if(doerror==1)
    {
        cout<<"invalid input"<<endl;
    }
    else
    {
        for(int t=0; t<numbers; t++)
        {
            cout<<result[t]<<endl;
        }
    }



    return 0;
}
