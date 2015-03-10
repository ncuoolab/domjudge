#include<iostream>
#include<cstdlib>
#include<string>
#include<ctype.h>
using namespace std;

bool Isstrdcl(string);
bool Isid(string);
bool Isstring(string);
bool Isquote(string);
bool Isprint(string);
string token(string);
bool check=true;
string astr[7];
int main()
{
    int count=0;
    string str;
     string temp="";
     cin >> str;
     if(Isstrdcl(str))
     {
           astr[count]=str;
           count++;
           cin >> str;
           if(Isid(str))
           {
                 astr[count]=str;
                 count++;
                 cin >> str;
                 if((int)str[0] == 34&& (int)str[str.size()-1]==34)
                 {
                     astr[count] = (char)34;
                     count ++;
                     for(int i=1;i<str.size()-1;i++)
                     {
                             temp = temp + str[i];
                     }
                     if(Isstring(temp))
                     {
                                       astr[count]=temp;
                                       count++;
                                       astr[count] = (char)34;
                                       count ++;
                                       cin >> str;
                                       if(Isprint(str))
                                       {
                                             astr[count]=str;
                                             count++;
                                             cin >> str;
                                             if(Isid(str))
                                             {
                                                 astr[count] = str;
                                                 check = true;
                                             }
                                             else
                                             check = false;
                                       }
                                       else
                                       check = false;
                     }
                     else
                     check = false;
                 }
                 else
                 check = false;
           }
           else
           check = false;


     }
     else
     {
         check = false;
     }
    if(check)
    {
        for(int i=0;i<7;i++)
        {
            cout << token(astr[i]) << " " << astr[i] << endl;
        }
    }
    else
    {
        cout << "valid input" << endl;
    }

    system("pause");
    return 0;
}

string token(string str)
{
       string type="";
       if(Isstrdcl(str))
       type = "strdcl";
       else if(Isquote(str))
       type = "quote";
       else if(Isprint(str))
       type = "print";
       else if(Isid(str))
       type = "id";
       else if(Isstring(str))
       type = "string";
       else
       type = "invalid type";

       return type;

}
bool Isstrdcl(string str)
{
     if(str == "s")
     return true;
     else
     return false;
}
bool Isid(string str)
{
     if(str.size()==1)
     {
          if(islower(str[0]) && str!="s" && str!="p")
          return true;
          else
          return false;
     }
     else
     return false;
}
bool Isstring(string str)
{
     for(int i=0;i<str.size();i++)
     {
             if(!isalnum(str[i]))
             return false;
     }
     return true;
}
bool Isquote(string str)
{
     if(str.size()==1)
     {
            if((int)str[0]==34)
            return true;
            else
            return false;
     }
     else
     return false;
}
bool Isprint(string str)
{
     if(str == "p")
     return true;
     else
     return false;
}

