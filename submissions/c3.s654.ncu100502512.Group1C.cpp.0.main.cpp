#include <iostream>
#include <cstdlib>
#include <cctype>
#include <string>

using namespace std;

char input[100];
int position1=0, position2=0, stop=0;
bool id=false, inum=false, no=false, final=true;

int main()
{
    cin >> input;
    for(int i=0; i<100; i++)
    {
        if(input[i] == '(')
        {
            position1 = i;
        }
        else if(input[i] == ')')
        {
            position2 = i;
        }
    }


    if(position1==0 || position2 ==0)
    {
        cout << "invalid input" << endl;
        final = false;
    }

    for(int i=0; i<position1; i++)
    {
        if(isalpha(input[i]) || input[i]=='_')
        {
            for(int j=position1+1; j<position2; j++)
            {
                if(isalpha(input[j]) || input[j]=='_')
                {
                    id = true;
                }
                else if(isdigit(input[j]))
                {
                    inum = true;
                }
                else if(input[j] == ' ')
                {
                    no = true;
                }
                else
                {
                    cout << "invalid input" << endl;
                    final = false;
                }
            }
        }
    }

    if(final == true)
    {
        cout << "id ";
        for(int i=0; i<position1; i++)
        {
            cout << input[i];
        }
        cout << endl;
        cout << "Iparenthesis (" <<endl;
        if(id == true)
        {
            cout << "id ";
            for(int j=position1+1; j<position2; j++)
            {
                cout << input[j];
            }
            cout << endl;

        }
        else if(inum == true)
        {
            cout << "inum ";
            for(int j=position1+1; j<position2; j++)
            {
                cout << input[j];
            }
            cout << endl;
        }
        else if(no == true)
        {

        }
        cout << "rparenthesis )" << endl;
    }

    return 0;
}
