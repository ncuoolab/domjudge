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
    int index = 0;
    int TOKENnim = 0;
    string input[100];
    string temp[100];

    while(cin >> input[index])
    {
        //cout << index << " " << input[index] << endl;
        index++;
        TOKENnim++;
    }

    index = 0;
    while(index < TOKENnim)
    {
        if(ifLevel(input[index]))
            temp[index] = "level " + input[index] + "\n";
            //cout << "level " << input << endl;
        else if(ifFirstName(input[index]))
            temp[index] = "FirstName " + input[index] + "\n";
            //cout << "FirstName " << input << endl;
        else if(ifLastName(input[index]))
            temp[index] = "LastName " + input[index] + "\n";
            //cout << "LastName " << input << endl;
        else if(ifcid(input[index]))
        {
            input[index] = "cid " + input[index] + "\n";
            //cout << "cid " << input << endl;
        }
        else if(ifbattle(input[index]))
            input[index] = "battle " + input[index] + "\n";
            //cout << "battle " << input << endl;
        else
        {
            cout << "invalid input";
            break;
        }
        index++;

    }

    return 0;
}
