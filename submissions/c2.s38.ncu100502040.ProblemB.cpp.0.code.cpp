
#include<iostream>
#include<string>
#include <stdio.h>

using namespace std;

string string_mid = "";
bool success = true;
bool id = false;
bool strdcl = false;
bool print = false;
bool quote = false;

int f_string(string s, int i)
{
    i++;
    string_mid = "";
    int string_length = 0;
    for(int j = i; j < s.size(); j++)
    {
        string_length++;
        if(s[j] != '"')
        {
            if(j == s.size() - 1)
            {
                success = false;
            }
            string_mid += s[j];
        }
        else
            break;

    }
    return string_length;
}

bool eng_check(char c)
{
    char eng[24] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'q', 'r', 't' ,'u', 'v', 'w', 'x', 'y', 'z'};
    bool eng_success = false;
    for(int i = 0; i < 24; i++)
    {
        if(c == eng[i])
            eng_success = true;
    }
    return eng_success;
}
int main()
{
	string s, s1, s2, terminal[5] = {"strdcl", "id", "quote", "string", "print"};

    //scanf("%d", &input);
	getline(cin,s1);
	getline(cin,s2);
	s = s1 + " " + s2;
	int type[s.size()];
	string name[s.size()];

    int now = 0;
    for(int i = 0; i < s.size(); i++)
    {
        switch(s[i])
        {
        case 's':
            if(!strdcl)
            {
                type[now] = 0;
                name[now] = s[i];
                strdcl = true;
            }
            else
                success = false;
            id = false;
            break;

        case 'p':

            if(!print)
            {
                type[now] = 4;
                name[now] = s[i];
                print = true;
            }
            else
                success = false;
            id = false;
            break;

        case '"':
            if(!quote)
            {
                type[now] = 2;
                name[now] = s[i];
                now++;
                int num;
                num = f_string(s, i);
                type[now] = 3;
                name[now] = string_mid;
                now++;
                type[now] = 2;
                name[now] = '"';
                i += (num + 1);
                quote = true;
            }
            else
                success = false;
            id = false;
            break;
        case ' ':
            now--;

            id = false;
            break;
        default:
            bool check = eng_check(s[i]);
            if(check)
            {
                if(id)
                {
                    success = false;
                }
                else
                {
                    type[now] = 1;
                    name[now] = s[i];
                    id = true;
                }

            }
            else
                success = false;

        }
        now++;
        if(!success)
            break;
    }

    if(success && strdcl && print && id)
    {
        for(int i = 0; i < now; i++)
        {
            cout << terminal[type[i]] << " " << name[i] << endl;

        }

    }
    else
    {
        cout << "valid input";
    }
	return 0;
}
