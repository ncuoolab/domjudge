#include <iostream>
using namespace std;
bool checkId(char);
bool checkString(char);
string standard[7] = {"strdcl", "id", "quote", "string", "quote", "print", "id"};

int main()
{
    char strdcl, fid, left, str[1000], right, print, lid;
    bool fail = false;
    cin >> strdcl >> fid >> str;

    if(strdcl != 's')
        fail = true;
    if(!checkId(fid))
        fail = true;

    int length = 0;
    while(str[length] != '\0')
        length++;

    if(str[0] != '\"')
        fail = true;
    else
        left = str[0];

    if(str[length - 1] != '\"')
        fail = true;
    else
        right = str[length - 1];

    for(int i = 0; i < length - 2; i++)
    {
        if(!checkString(str[i + 1]))
        {
            fail = true;
            break;
        }
        else
        {
            str[i] = str[i + 1];
        }
    }
    str[length - 2] = '\0';

    if(fail == true)
    {
        cout << "valid input" << endl;
        return 0;
    }

    cin >> print >> lid;

    if(print != 'p')
        fail = true;
    if(lid != fid)
        fail = true;

    // end second line check
    if(fail == true)
    {
        cout << "valid input" << endl;
        return 0;
    }
    else
    {
        for(int i = 0; i < 7; i++) {
            cout << standard[i] << " ";
            switch(i) {
                case 0:
                    cout << strdcl;
                    break;
                case 1:
                    cout << fid;
                    break;
                case 2:
                    cout << left;
                    break;
                case 3:
                    cout << str;
                    break;
                case 4:
                    cout << right;
                    break;
                case 5:
                    cout << print;
                    break;
                case 6:
                    cout << lid;
                    break;
                default:
                    break;
            }
            cout << endl;
        }
    }
    return 0;
}

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
