#include<iostream>

//48~57:0~9  65~90:A~Z  97~122:a~z

using namespace std;

bool success = true, Theend = false;
int i_Fname = 0, i_Lname = 0, string_num = 0, level_num = 0, cid_num = 0;
string string_name[6];
int level(string s, int i)
{
    int length = 0;
    for(int j = i+1; j < s.size(); j++)
    {
        int temp = s[j];
        //cout << "temp:" << temp << endl;
        if(s[j] >= '0' && s[j] <= '9')
        {
            string_name[string_num] += s[j];

        }
        else if(s[j] == ' ')
        {
            break;
        }
        else
        {
            success = false;
            //cout << "0" << endl;
            break;
        }
        length++;
    }
    if(i_Fname == 2)
        success = false;
    return length;
}

int Fname(string s, int i)
{
    int length = 0;
    for(int j = i+1; j < s.size(); j++)
    {
        int temp = s[j];
        if(s[j] >= 'a' && s[j] <= 'z')
        {
            string_name[string_num] += s[j];
        }
        else if(s[j] == ' ')
        {
            break;
        }
        else
        {
            success = false;
            break;
           // cout << "1" << endl;
        }
        length++;
    }
    i_Fname++;
    if(i_Fname == 2)
        Theend = true;
    return length;
}

int Lname(string s, int i)
{
    int length = 0;
    for(int j = i+1; j < s.size(); j++)
    {
        int temp = s[j];
        if(s[j] == 'a' || (s[j] > 'b' && s[j] <= 'z'))
        {
            string_name[string_num] += s[j];
        }
        else if(s[j] == ' ')
        {
            break;
        }
        else if(s[j] == '\n')
        {

        }
        else
        {
            success = false;
            break;
           // cout << "2" << endl;
        }
        length++;
    }
    i_Lname++;
    if(i_Lname == 2)
        Theend = true;
    return length;
}

int cid(string s, int i)
{
    int length = 0;
    for(int j = i+1; j < s.size(); j++)
    {
        int temp = s[j];
        if(s[j] >= '0' && s[j] <= '9')
        {
            string_name[string_num] += s[j];
        }
        else if(s[j] == ' ')
        {
            break;
        }
        else
        {
            success = false;
            break;
            //cout << "3" << endl;
        }
        length++;
    }
    if(cid_num == 2)
        success = false;
    i_Lname++;
    return length;
}




int main()
{
    string s = "", s1, s_name[5] = {"level", "FirstName", "LastName", "cid", "battle"};
    char c;
    int name[6];
    int ans1[4] = {0, 3, 4, 3};
    int ans2[5] = {0, 3, 4, 1, 2};
    int ans3[5] = {0, 1, 2, 4, 3};
    int ans4[6] = {0, 1, 2, 4, 1, 2};
    string z;
    while(getline(cin,z))
    {
        s = s + z + " ";
    }
    for(int i = 0; i < s.size() - 1; i++)
    {
        //int temp = s[i];
        //cout << temp << endl;
        if(!success)
        {
            break;
        }
        if(s[i]  == 'l')
        {
            string_name[string_num] += s[i];
            int l = level(s, i);
            i += l+1;
            name[string_num] = 0;
            string_num++;
        }
        else if(s[i] == 'b')
        {
            string_name[string_num] += s[i];
            name[string_num] = 4;
            string_num++;
        }
        else if(s[i] >= 'A' && s[i] <= 'Z')
        {
            string_name[string_num] += s[i];
            int l = Lname(s, i);
            i += l+1;
            name[string_num] = 1;
            string_num++;
        }
        else if(s[i] == 'a' || (s[i] > 'b' && s[i] <= 'z'))
        {
            string_name[string_num] += s[i];
            int l = Fname(s, i);
            i += l+1;
            name[string_num] = 2;
            string_num++;
        }
        else if(s[i] >= '0' && s[i] <= '9')
        {
            string_name[string_num] += s[i];
            int l = cid(s, i);
            i += l+1;
            name[string_num] = 3;
            string_num++;

        }
        else if(s[i] == ' ')
        {

        }
        else
        {

           success = false;
           break;
            //cout << "4" << endl;
        }
        if(string_num > 6)
        {
            success = false;
            break;
        }


    }
    for(int i = 0; i < string_num; i++)
    {
        if(string_num == 4)
        {
            for(int i = 0; i < string_num; i++)
            {
                if(name[i] != ans1[i])
                    success = false;
            }
        }
        else if(string_num == 5)
        {
            for(int i = 0; i < string_num; i++)
            {
                if(name[i] != ans2[i] && name[i] != ans3[i] )
                    success = false;
            }
        }
        else if(string_num == 6)
        {
            for(int i = 0; i < string_num; i++)
            {
                if(name[i] != ans4[i])
                    success = false;
            }
        }
    }
    if(success)
    {
        for(int i = 0; i < string_num; i++)
        {
            cout << s_name[name[i]] << " " << string_name[i] << endl;
        }


    }
    else
    {
        cout << "invalid input";

    }

    return 0;
}
