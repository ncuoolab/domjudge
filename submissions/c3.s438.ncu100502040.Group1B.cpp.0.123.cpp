#include<iostream>

//48~57:0~9  65~90:A~Z  97~122:a~z

using namespace std;

bool success = true;
int i_Fname = 0, i_Lname = 0, string_num = 0;
string string_name[6];
int level(string s, int i)
{
    int length = 0;
    for(int j = i+1; j < s.size(); j++)
    {
        int temp = s[j];
        //cout << "temp:" << temp << endl;
        if(temp > 47 && temp < 58)
        {
            string_name[string_num] += s[j];

        }
        else if(temp == 32)
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
    return length;
}

int Fname(string s, int i)
{
    int length = 0;
    for(int j = i+1; j < s.size(); j++)
    {
        int temp = s[j];
        if(temp > 96 && temp < 123)
        {
            string_name[string_num] += s[j];
        }
        else if(temp == 32)
        {
            break;
        }
        else
        {
            success = false;
            //cout << "1" << endl;
        }
        length++;
    }
    i_Fname++;
    return length;
}

int Lname(string s, int i)
{
    int length = 0;
    for(int j = i+1; j < s.size(); j++)
    {
        int temp = s[j];
        if(temp == 97 || (temp > 98 && temp < 123))
        {
            string_name[string_num] += s[j];
        }
        else if(temp == 32)
        {
            break;
        }
        else
        {
            success = false;
            //cout << "2" << endl;
        }
        length++;
    }
    i_Lname++;
    return length;
}

int cid(string s, int i)
{
    int length = 0;
    for(int j = i+1; j < s.size(); j++)
    {
        int temp = s[j];
        if(temp > 47 && temp < 58)
        {
            string_name[string_num] += s[j];
        }
        else if(temp == 32)
        {
            break;
        }
        else
        {
            success = false;

            //cout << "3" << endl;
        }
        length++;
    }
    i_Lname++;
    return length;
}




int main()
{
    string s = "", s1, s_name[5] = {"level", "FirstName", "LastName", "cid", "battle"};
    int name[6];
    int ans1[4] = {0, 3, 4, 3};
    int ans2[5] = {0, 3, 4, 1, 2};
    int ans3[5] = {0, 1, 2, 4, 3};
    int ans4[6] = {0, 1, 2, 4, 1, 2};
    while(getline(cin,s1))
    {
        s += s1 + " ";
    }
    //cout << s;
    for(int i = 0; i < s.size() - 1; i++)
    {
        int temp = s[i];
        //cout << temp << endl;
        if(temp  == 108)
        {
            string_name[string_num] += s[i];
            int l = level(s, i);
            i += l+1;
            name[string_num] = 0;
            string_num++;
        }
        else if(temp > 64 && temp < 91)
        {
            string_name[string_num] += s[i];
            int l = Lname(s, i);
            i += l+1;
            name[string_num] = 1;
            string_num++;
        }
        else if(temp == 97 || (temp > 98 && temp < 123))
        {
            string_name[string_num] += s[i];
            int l = Fname(s, i);
            i += l+1;
            name[string_num] = 2;
            string_num++;
        }
        else if(temp > 47 && temp < 58)
        {
            string_name[string_num] += s[i];
            int l = cid(s, i);
            i += l+1;
            name[string_num] = 3;
            string_num++;

        }
        else if(temp == 98)
        {
            string_name[string_num] += s[i];
            name[string_num] = 4;
            string_num++;
        }
        else if(temp == 32)
        {

        }
        else
        {
            success = false;
            //cout << "4" << endl;
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
        for(int i = 0; i < string_num; i++)
        {
            cout << s_name[name[i]] << " " << string_name[i] << endl;
        }
    }

    return 0;
}
