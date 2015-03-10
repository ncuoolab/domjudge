#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
using namespace std;

bool is_id(string s)
{
    if(s.length() == 1)
    {
        if("a" <= s && s <= "z")
            return 1;
        else
            return 0;
    }
}

bool is_assign(string s)
{
    if(s == "=")
        return 1;
    else
        return 0;
}

bool is_inum(string s)
{
    for(int i = 0 ; i < s.length() ; i++)
    {
        if(s[i] < (int)"0" || s[i] > (int)"9")
            return 0;
    }

    return 1;
}

void stmt_match()
{
    string SRC , temp;
    string a , b , c;
    bool flag = 1;
    while(cin >> SRC)
    {
        if(is_id(SRC))
        {
            //cout << 1 << endl;
            temp += "id " + SRC + "\n";
            if(is_assign(SRC))
            {
                //cout << 2 << endl;
                temp += "assign " + SRC + "\n";
                if(is_inum(SRC))
                {
                    //cout << 3 << endl;
                    temp += "inum " + SRC + "\n";
                }
                else
                {
                    flag = 0;
                    break;
                }
            }
            else
            {
                flag = 0;
                break;
            }
        }
        else
        {
            flag = 0;
            break;
        }
    }

    if(flag)
        cout << temp;
    else
        cout << "invalid input";

}

int main()
{
    stmt_match();

    return 0;
}
