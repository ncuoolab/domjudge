#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

bool isinum(string s)
{
    if(!((int)s[0] >= (int)'0' && (int)s[0] <= (int)'9') && s.length() != 1)
    {
        //cout << "invalid input" << endl;
        return 0;
    }
    //cout << 'inum ' + s + '\n';
    return 1;
}

bool isid(string s)
{
    if(!((int)s[0] >= (int)'a' && (int)s[0] <= (int)'z') && s.length() != 1)
    {
        //cout << "invalid input" << endl;
        return 0;
    }
    //cout << 'id ' + s + '\n';
    return 1;
}

bool isassin(string s)
{
    if(s[0] != '=' || s.length() > 1)
    {
        //cout << "invalid input" << endl;
        return 0;
    }
    //cout << 'id ' + s + '\n';
    return 1;
}

int main()
{
    string temp;

    getline(cin , temp);

    int counttoken = 0;
    for(int i = 0 ; i < temp.length() ; i++)
    {
        if((int)temp[i] ==' ')
            counttoken++;
    }

    string token[counttoken];
    counttoken = 0;
    for(int i = 0 ; i < temp.length() ; i++)
    {
        if((int)temp[i] != ' ')
            token[counttoken] += temp[i];
        else
            counttoken++;
    }

    if(isid(token[0]) && isassin(token[1]) && isid(token[2]))
    {
        cout << "id " << token[0] << endl;
        cout << "assign " << token[1] << endl;
        cout << "id " << token[2] << endl;
        return 0;
    }
    else if(isid(token[0]) && isassin(token[1]) && isinum(token[3]))
    {
        cout << "id " << token[0] << endl;
        cout << "assign " << token[1] << endl;
        cout << "inum " << token[2] << endl;
        return 0;
    }
    else
    {
        cout << "invalid input" << endl;
        return 0;
    }


    return 0;
}
