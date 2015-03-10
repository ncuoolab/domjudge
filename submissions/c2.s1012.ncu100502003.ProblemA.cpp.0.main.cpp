#include <iostream>
#include <cstdlib>
#include <cctype> //使用字元的檢查需要的標頭檔
#include <string>

using namespace std;

string input;
int space[2]={};
char id1, id2;
int inum;
bool num=false, id=false;

int main()
{
    getline(cin, input);
    int tmp=0;
    for(int i=0; i<input.length(); i++)
    {
        if(input[i] == ' ')
        {
            space[tmp] = i;
            tmp++;
        }
    }

    if(space[0] == 1)
    {
        if(islower(input[0]))
        {
            if(input[2] == '=')
            {
                id1 = input[0];
                if(space[1] == 3)
                {
                    if(islower(input[4]))
                    {
                        if(input.length() == 5)
                        {
                            id = true;
                            id2 = input[4];
                            cout << "id " << id1 << endl;
                            cout << "assign =" << endl;
                        }
                        else
                           cout << "valid input" << endl;
                    }
                    else if(isdigit(input[4]))
                    {
                        if(input.length() == 5)
                        {
                            num = true;
                            inum = input[4]-'0'; // char轉 int
                            cout << "id " << id1 << endl;
                            cout << "assign =" << endl;
                        }
                        else
                           cout << "valid input" << endl;
                    }
                    else
                        cout << "valid input" << endl;
                }
                else
                    cout << "valid input" << endl;
            }
            else
                cout << "valid input" << endl;
        }
        else
            cout << "valid input" << endl;
    }
    else
    {
        cout << "valid input" << endl;
    }

    if(id==true)
    {
        cout << "id " << id2 << endl;
    }
    else if(num==true)
    {
        cout << "inum " << inum << endl;
    }

    system("pause");
    return 0;
}
