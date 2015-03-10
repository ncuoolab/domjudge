#include<iostream>
#include<string>
using namespace std;
int doerror=0,numbers=0;
string result[6]= {};

/*void Dostring(string tring)
{
    if((tring[0]>=97&&tring[0]<=122)||(tring[0]>=65&&tring[0]<=90)||(tring[0]>=48&&tring[0]<=57))
    {
        int Noerror=0;
        for(int t=1; t<tring.length(); t++)
        {
            if(!((tring[t]>=97&&tring[t]<=122)||(tring[t]>=65&&tring[t]<=90)||(tring[t]>=48&&tring[t]<=57)))
            {
                Noerror=1;
            }
        }
        if(Noerror==0)
        {
            result[numbers]="string "+tring;
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
}*/

void Doquote(string quote)
{
    if(quote.length()==1)
    {
        if(quote[0]==92||quote[0]==34)
        {
            result[numbers]="quote "+quote;
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

void Dostrdcl (string strdcl)
{
    if(strdcl.length()==1)
    {
        if(strdcl[0]==115)
        {
            result[numbers]="strdcl "+strdcl;
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

void Doid(string id)
{
    if(id.length()==1)
    {
        if((id[0]>=97&&id[0]<=111)||id[0]==113||id[0]==114||(id[0]>=116&&id[0]<=122))
        {
            result[numbers]="id "+id;
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
void Doprint(string print)
{
    if(print.length()==1)
    {
        if(print[0]==112)
        {
            result[numbers]="print "+print;
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
void Doastring(string astring)
{
    string quote1="",tring="",quote2="";

    int goswich=0;
    for(int t=0; t<astring.length(); t++)
    {
        if(goswich==0)
        {
            if(astring[t]==92||astring[t]==34)
            {
                goswich+=1;
                quote1+=astring[t];
            }
            else
            {
                doerror=1;
            }
        }
        else if(goswich==1)
        {
            if(astring[t]==92||astring[t]==34)
            {
                goswich+=1;
                quote2+=astring[t];
            }
            else
            {
                tring+=astring[t];
            }
        }
        else
        {
            doerror=1;
        }
    }
    Doquote(quote1);
    //Dostring(tring);
    result[numbers]="string "+tring;
            numbers++;
    Doquote(quote2);

}
void DoDcl(string Dcl)
{
    string strdcl="",id="",astring="";

    int goswich=0;
    for(int t=0; t<Dcl.length(); t++)
    {
        if(Dcl[t]==' ')
        {
            goswich+=1;
        }
        else if(Dcl[t]==92||Dcl[t]==34){
            astring+=Dcl[t];
            goswich+=1;
        }
        else if(goswich==0)
        {
            strdcl+=Dcl[t];
        }
        else if(goswich==1)
        {
            id+=Dcl[t];
        }
        else if(goswich==2)
        {
            astring+=Dcl[t];
        }
    }
    Dostrdcl(strdcl);
    Doid(id);
    Doastring(astring);

}

void DoStmt(string Stmt)
{
    string print="",id="";

    int goswich=0;
    for(int t=0; t<Stmt.length(); t++)
    {
        if(Stmt[t]==' ')
        {
            goswich+=1;
        }
        else if(goswich==0)
        {
            print+=Stmt[t];
        }
        else if(goswich==1)
        {
            id+=Stmt[t];
        }
    }
    Doprint(print);
    Doid(id);
}


int main()
{

    string Dcl="",Stmt="";
    getline(cin,Dcl);
    getline(cin,Stmt);

    DoDcl(Dcl);
    DoStmt(Stmt);
    for(int t=0; t<numbers; t++)
        {
            cout<<result[t]<<endl;
        }



    return 0;
}
