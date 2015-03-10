#include <iostream>
#include <cstdlib>
#include <cctype>
#include <string>

using namespace std;

//int space1[2]={}, space2[2]={};
char input1[20]={};
char input2[20]={};
char input3[20]={};
char input4[20]={};
char input5[20]={};
char input6[20]={};
bool right=true;
int place=0;
int id1, id2;


int main()
{
    cin >> input1;
    cin >> input2;
    cin >> input3;
    cin >> input4;

    while(right != false)
    {
        if(input3[0] != 'b' && input4[0] == 'b')
        {
            cin >> input5;
            if(isalpha(input5[0])
            {
                cin >> input6;
                for(int i=0; i<20; i++)
                {
                    if(input5[i] == '\n')
                        place = i
                }
                if(isupper(input5[0]))
                {
                    for(int j=1; j<place; j++)
                    {
                        if(islower(input5[j]))
                        {
                        }
                        else
                        {
                            cout << "invalid input" << endl;
                            right = false;
                        }
                    }
                }
                else
                {
                    cout << "invalid input" << endl;
                    right = false;
                }
                for(int i=0; i<20; i++)
                {
                    if(input6[i] == '\n')
                        place = i
                }
                for(int j=1; j<place; j++)
                {
                    if(islower(input6[j]))
                    {
                        if(input6[j] == 'b')
                        {
                            cout << "invalid input" << endl;
                            right = false;
                        }
                    }
                    else
                    {
                        cout << "invalid input" << endl;
                        right = false;
                    }

                }
            }

            if(input1[0] == 'l')
            {
                for(int i=0; i<20; i++)
                {
                    if(input1[i] == '\n')
                        place = i
                }
                if(isupper(input1[0]))
                {
                    for(int j=1; j<place; j++)
                    {
                        if(islower(input1[j]))
                        {
                        }
                        else
                        {
                            cout << "invalid input" << endl;
                            right = false;
                        }
                    }
                }
                else
                {
                    cout << "invalid input" << endl;
                    right = false;
                }


                for(int i=0; i<20; i++)
                {
                    if(input2[i] == '\n')
                        place = i
                }
                for(int j=1; j<place; j++)
                {
                    if(islower(input2[j]))
                    {
                        if(input2[j] == 'b')
                        {
                            cout << "invalid input" << endl;
                            right = false;
                        }
                    }
                    else
                    {
                        cout << "invalid input" << endl;
                        right = false;
                    }

                }

        /*int a=0;
        for(int i=1; i<50; i++)
        {
            if(input1[i] == ' ')
            {
                space1[a] = i; // 存空白的所在處
                cout << space1[a];
                a++;
            }
        }
        for(int j=1; j<space1[0]; j++)
        {
            if(isdigit(input1[j])) // do nothing
            {
            }
            else
            {
                cout << "invalid input" << endl;
            }
        }*/
            }
            else
            {
                cout << "invalid input" << endl;
                right = false;
            }

        }
        else // 地一行為level+id input3即battle
        {
            if(isalpha(input4[0])
            {
                cin >> input5;
                for(int i=0; i<20; i++)
                {
                    if(input4[i] == '\n')
                        place = i
                }
                if(isupper(input4[0]))
                {
                    for(int j=1; j<place; j++)
                    {
                        if(islower(input4[j]))
                        {
                        }
                        else
                        {
                            cout << "invalid input" << endl;
                            right = false;
                        }
                    }
                }
                else
                {
                    cout << "invalid input" << endl;
                    right = false;
                }

                for(int i=0; i<20; i++)
                {
                    if(input5[i] == '\n')
                        place = i
                }
                for(int j=1; j<place; j++)
                {
                    if(islower(input5[j]))
                    {
                        if(input5[j] == 'b')
                        {
                            cout << "invalid input" << endl;
                            right = false;
                        }
                    }
                    else
                    {
                        cout << "invalid input" << endl;
                        right = false;
                    }

                }
            }
            else if(isdigit(input4[0]))
            {
                for(int i=0; i<20; i++)
                {
                    if(input4[i] == '\n')
                        place = i
                }
                for(int j=1; j<place; j++)
                {
                    if(isdigit(input4[j]))
                    {

                    }
                    else
                    {
                        cout << "invalid input" << endl;
                        right = false;
                    }
                }
            }
            else
            {
                cout << "invalid input" << endl;
                right = false;
            }


        }



    /*for(int i=0; i<20; i++)
    {
        cout << input1[i];
    }
    cout << endl;
    for(int i=0; i<20; i++)
    {
        cout << input2[i];
    }*/
    }



    system("pause");
    return 0;
}
