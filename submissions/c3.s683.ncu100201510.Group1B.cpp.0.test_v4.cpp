#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;

bool ifLevel(string s)
{
    if(s.length() < 2)
        return 0;

    bool flag = 1;
    if(s[0] == 'l')
    {
        for(int i = 1 ; i < s.length() ; i++)
        {
            if((int)s[i] < 58 && (int)s[i] > 47)
                flag *= 1;
            else
                flag *= 0;
        }
    }
    else
        flag = 0;

    return flag;
}

bool ifFirstName(string s)
{
    if(s.length() == 0)
        return 0;

    bool flag = 1;
    if((int)'A' <= (int)s[0] && (int)s[0] <= (int)'Z')
    {
        for(int i = 1 ; i < s.length() ; i++)
        {
            if((int)s[i] <= (int)'z' && (int)s[i] >= (int)'a')
                flag *= 1;
            else
                flag *= 0;
        }
    }
    else
        flag = 0;

    return flag;
}

bool ifLastName(string s)
{
    if(s.length() > 0)
    {
        bool flag = 1;
        for(int i = 0 ; i < s.length() ; i++)
        {
            if(('a' <= (int)s[i] && (int)s[i] < 'z') && s[i] != 'b')
                flag *= 1;
            else
                flag *= 0;
        }
        return flag;
    }
    else
        return 0;


}

bool ifcid(string s)
{
    if(s.length() > 0)
    {
        bool flag = 1;
        for(int i = 0 ; i < s.length() ; i++)
        {
            if('0' <= (int)s[i] && (int)s[i] <= '9')
                flag *= 1;
            else
                flag *= 0;
        }
        return flag;
    }
    else
        return 0;
}

bool ifbattle(string s)
{
    if(s == "b")
        return 1;
    else
        return 0;
}

int main()
{
    string input;
    //cout << "please input : " << endl << endl;
    string temp;

    while(cin >> input)
    {
        if(ifLevel(input))
            cout << "level " << input << endl;
        else if(ifFirstName(input))
            cout << "FirstName " << input << endl;
        else if(ifLastName(input))
            cout << "LastName " << input << endl;
        else if(ifcid(input))
        {
            while(cin >> temp)
            {
                if(!ifFirstName(temp) && !ifbattle(temp))
                {
                    cout << "invalid input";
                    return 0;
                }
                else
                    break;
            }
            cout << "cid " << input << endl;

            if(ifbattle(input))
            cout << "battle " << input << endl;
            else
            {
                cout << "invalid input";
                break;
            }
        }
        else if(ifbattle(input))
            cout << "battle " << input << endl;
        else
        {
            cout << "invalid input";
            break;
        }

    }

    return 0;
}
