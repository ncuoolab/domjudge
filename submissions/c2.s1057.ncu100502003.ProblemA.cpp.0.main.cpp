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
int counter;
string number;

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
                        if(input.length() >= 5)
                        {
                            num = true;
                            /*for(int k=4; k<input.length(); k++)
                            {
                                counter++;
                            }
                            char *tmp;
                            tmp = new char[counter];

                            for(int m=4; m<input.length(); m++)
                            {
                                tmp[m] = input[m];

                                number.assign(tmp[m]);
                                inum = number;
                                //tmp = input[4]-'0'; // char轉 int

                            }*/
                            int tmp[3] = {};

                            for(int n=4; n<7; n++)
                            {
                                tmp[n]=input[n]-'0';
                            }
                            inum = tmp[4]*100+tmp[5]*10+tmp[6];
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
