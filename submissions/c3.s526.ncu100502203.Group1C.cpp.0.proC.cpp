#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

bool checkID(char c)
{
    if(c>='a' && c<='z')
        return true;
    if(c>='A' && c<='Z')
        return true;
    if(c=='_')
        return true;
    return false;
}

bool checkNUM(char c)
{
    if(!(c>='0' && c<='9'))
        return false;
    return true;
}

int main()
{
    bool fail = false;
    char inputS[200], id[200], para[200];
    int inum=0;
    cin >> inputS;
    int count=0, length=0;
    while(inputS[count++] != '\0')
        length++;
    count=0;
    while(inputS[count] != '(')
    {
        if(inputS[count] == '\0')
        {
            fail = true;
            break;
        }
        if(checkID(inputS[count]))
            id[count] = inputS[count];
        else
            fail = true;
        count++;
    }
    id[count++] = '\0';

    int pcount=0;
    bool optID = false;
    if(checkID(inputS[count]))
    {
        optID = true;
        while(inputS[count] != ')')
        {
            if(inputS[count] == '\0')
            {
                fail = true;
                break;
            }
            if(checkID(inputS[count]))
                para[pcount] = inputS[count];
            else
                fail = true;
            pcount++;
            count++;
        }
    }
    else if(checkNUM(inputS[count]))
    {
        while(inputS[count] != ')')
        {
            if(inputS[count] == '\0')
            {
                fail = true;
                break;
            }
            if(checkNUM(inputS[count]))
                para[pcount] = inputS[count];
            else
                fail = true;
            pcount++;
            count++;
        }
    }
    else
        fail = true;

    if(fail)
        cout << "invalid input" << endl;
    else
    {
        cout << "id " << id << endl;
        cout << "lparenthesis (" << endl;
        if(optID)
            cout << "id " << para << endl;
        else
            cout << "inum " << para << endl;
        cout << "rparenthesis )" << endl;
    }


    return 0;
}
