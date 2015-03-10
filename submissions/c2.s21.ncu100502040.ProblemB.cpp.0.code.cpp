
#include<iostream>
#include<string>

using namespace std;

string string_mid = "";
bool success = true;

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
	string s, terminal[5] = {"strdcl", "id", "quote", "string", "print"};

	getline(cin,s);
	int type[s.size()];
	string name[s.size()];

    int now = 0;
    for(int i = 0; i < s.size(); i++)
    {
        switch(s[i])
        {
        case 's':
            type[now] = 0;
            name[now] = s[i];
            break;

        case 'p':
            type[now] = 4;
            name[now] = s[i];
            break;

        case '"':
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
            break;
        case ' ':
            now--;
            break;
        default:
            bool check = eng_check(s[i]);
            if(check)
            {
                type[now] = 1;
                name[now] = s[i];
            }
            else
                success = false;

        }
        now++;
        if(!success)
            break;
    }

    if(success)
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
