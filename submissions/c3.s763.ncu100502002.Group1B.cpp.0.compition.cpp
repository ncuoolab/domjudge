#include<iostream>
#include<cstdlib>
#include<string>
#include <ctype.h>
using namespace std;
string token(string);
bool Islevel(string);
bool IsFirstName(string);
bool IsLastName(string);
bool Iscid(string);
bool Isbattle(string);
void stmt();
bool check = true;
string astr[6];
string str;
int count=0;
int main()
{
    //cout <<token("Malfurion")  << endl;
    stmt();
    stmt();
    if(check)
    {
        for(int i=0;i<count;i++)
        {
            cout << token(astr[i]) << " " << astr[i] << endl;
        }
    }
    else
    {
        cout << "invalid input" << endl;
    }



    system("pause");
    return 0;
}

string token(string str)
{
    string type;
    if(Islevel(str))
        type = "level";
    else if(IsFirstName(str))
        type = "FirstName";
    else if(IsLastName(str))
        type = "LastName";
    else if(Iscid(str))
        type = "cid";
    else if(Isbattle(str))
        type = "battle";
    else
        type = "invalid input";
    return type;

}
bool Islevel(string str)
{
    bool ok;
    if(str[0]=='l')
    {
        for(int i=1;i<str.size();i++)
        {
            if(!isdigit(str[i]))
                return false;

        }
        return true;
    }
    else
        return false;

}
bool IsFirstName(string str)
{
    if(isupper(str[0]))
    {
        for(int i=1;i<str.size();i++)
        {
            if(!isupper(str[i]))
            {
                if(!isalpha(str[i]))
                return false;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
}
bool IsLastName(string str)
{

        for(int i=0;i<str.size();i++)
        {
            if(!isupper(str[i]))
            {
                if(!isalpha(str[i])||str[i]=='b')
                return false;
            }
            else
            {
                return false;
            }
        }
        return true;
}
bool Iscid(string str)
{
    for(int i=0;i<str.size();i++)
    {
        if(!isdigit(str[i]))
            return false;
    }
    return true;
}
bool Isbattle(string str)
{
    if(str.size()==1)
    {
        if(str[0]=='b')
            return true;
        else
            return false;
    }
    return false;
}


void stmt()
{

        cin>>str;

        if(token(str) == "battle" ||token(str) == "level")
        {
            astr[count] = str;
            count ++;
            cin >> str;
            //cout << str << endl;
            if(token(str) != "cid")
            {
                if(token(str) == "FirstName")
                {
                    astr[count] = str;
                    count ++;
                    cin >> str;
                    if(token(str) == "LastName")
                    {
                        astr[count] = str;
                        count ++;
                    }
                    else
                    {
                        check = false;
                        //cout << "1" << endl;
                    }
                }
                else
                {
                    check = false;
                    //cout << 2 << endl;
                }
            }
            else
            {
                astr[count] = str;
                    count ++;
                //check = false;
                //cout << 3 << endl;
            }
        }
        else
        {
            check = false;
            //cout << 4 << endl;
        }

}








bool Proc(string str)
{

    cin >> str;
    if(token(str)=="level")
        {
            cout << "level";
            cin>>str;
            if(token(str)=="cid" ||token(str)== "FirstName")
            {
                cout << "cid fn";
                if(token(str)== "FirstName")
                {
                    cout <<"fn";
                    if(token(str)== "LastName")
                    {
                        cin >> str;
                        if(token(str)== "battle")
                            return true;
                    }

                }
                else
                {
                    cin >> str;
                    if(token(str)== "battle")
                            return true;
                }

            }
        }
        else
            return false;

}/*
if(count==0)
        {
            if(token(str)=="level")
            {
                str_array[count] = str;
                count ++;
                cout << "level"<<endl;
                cout << count << endl;
            }
            else
            {
                cout << "invalid input" << endl;
                break;
            }

        }
        else if(count == 1)
        {
            if(token(str)=="cid"||"FirstName")
            {
                if(token(str)=="cid")
                {
                    str_array[count] = str;
                    count = count + 2;
                    cout << "cid"<<endl;
                    cout << count << endl;
                }
                else
                {
                    cin >> str;
                    if(token(str)=="LastName")
                    {
                        str_array[count] = str;
                        count ++;
                        cout << "LastName"<<endl;
                        cout << count << endl;
                    }
                    else
                    {
                        cout << "invalid input" << endl;
                        break;
                    }
                }

            }
            else
            {
                cout << "invalid input" << endl;
                break;
            }if(count==0)
        {
            if(token(str)=="level")
            {
                str_array[count] = str;
                count ++;
                cout << "level"<<endl;
                cout << count << endl;
            }
            else
            {
                cout << "invalid input" << endl;
                break;
            }

        }
        else if(count == 1)
        {
            if(token(str)=="cid"||"FirstName")
            {
                if(token(str)=="cid")
                {
                    str_array[count] = str;
                    count = count + 2;
                    cout << "cid"<<endl;
                    cout << count << endl;
                }
                else
                {
                    cin >> str;
                    if(token(str)=="LastName")
                    {
                        str_array[count] = str;
                        count ++;
                        cout << "LastName"<<endl;
                        cout << count << endl;
                    }
                    else
                    {
                        cout << "invalid input" << endl;
                        break;
                    }
                }

            }
            else
            {
                cout << "invalid input" << endl;
                break;
            }
        }
        else if(count ==3)
        {
            if(token(str)=="battle")
            {
                str_array[count] = str;
                count ++;
            }
            else
            {
                cout << "invalid input" << endl;
                break;
            }
        }
        else if(count == 4)
        {
            if(token(str)=="cid"||"FirstName")
            {
                if(token(str)=="cid")
                {
                    str_array[count] = str;
                    count = count + 2;
                }
                else
                {
                    cin >> str;
                    if(token(str)=="LastName")
                    {
                        str_array[count] = str;
                        count ++;
                    }
                    else
                    {
                        cout << "invalid input" << endl;
                        break;
                    }
                }

            }
            else
            {
                cout << "invalid input" << endl;
                break;
            }


        }
        }
        else if(count ==3)
        {
            if(token(str)=="battle")
            {
                str_array[count] = str;
                count ++;
            }
            else
            {
                cout << "invalid input" << endl;
                break;
            }
        }
        else if(count == 4)
        {
            if(token(str)=="cid"||"FirstName")
            {
                if(token(str)=="cid")
                {
                    str_array[count] = str;
                    count = count + 2;
                }
                else
                {
                    cin >> str;
                    if(token(str)=="LastName")
                    {
                        str_array[count] = str;
                        count ++;
                    }
                    else
                    {
                        cout << "invalid input" << endl;
                        break;
                    }
                }

            }
            else
            {
                cout << "invalid input" << endl;
                break;
            }


        }



*/
