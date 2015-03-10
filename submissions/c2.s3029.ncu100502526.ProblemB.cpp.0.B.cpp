#include <iostream>

using namespace std;

bool checkId(char c)
{
    if(c <= 'o' && c >= 'a')
        return true;
    if(c == 'q' || c == 'r')
        return true;
    if(c <= 'z' && c >= 't')
        return true;
    return false;
}

bool checkString(char c)
{
    if(c <= 'z' && c >= 'a')
        return true;
    if(c <= 'Z' && c >= 'A')
        return true;
    if(c <= '9' && c >= '0')
        return true;
    return false;
}

int main()
{
    char strdcl, id, pid, quoteL, str[999], quoteR, print;
    // first input line
    cin >> strdcl >> id >> str;
    // cout << strdcl << " " << id << " " << str;
    bool fail = false;
    if(strdcl != 's')
        fail = true;
    if(!checkId(id))
        fail = true;

    // check string
    int length = 0;
    while(str[length] != '\0')
        length++;
    // left
    if(str[0] != '\"')
        fail = true;
    else
        quoteL = str[0];
    // right
    if(str[length - 1] != '\"')
        fail = true;
    else
        quoteR = str[length - 1];

    for(int i=0; i<length-2; i++)
    {
        if(!checkString(str[i+1]))
        {
            fail = true;
            break;
        }
        else
        {
            str[i] = str[i+1];
        }
    }
    str[length-2] = '\0';

    // end first line check
    if(fail == true)
    {
        cout << "valid input" << endl;
        return 0;
    }

    // second line input check
    cin >> print >> pid;

    if(print != 'p')
        fail = true;
    if(pid != id)
        fail = true;

    // end second line check
    if(fail == true)
    {
        cout << "valid input" << endl;
        return 0;
    }
    else
    {
        cout << "strdcl " << strdcl << endl;
        cout << "id " << id << endl;
        cout << "quote " << quoteL << endl;
        cout << "string " << str << endl;
        cout << "quote " << quoteR << endl;
        cout << "print " << print << endl;
        cout << "id " << pid << endl;
    }
    return 0;
}
