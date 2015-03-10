#include <iostream>
#include <cstdlib>
#include <cctype>
#include <string>

using namespace std;

bool id1=false, id2=false;
bool name1=false, name2=false;
string input;
int space[10];
int space_count=0;


int main()
{
    getline(cin, input);
    for(int i=0; i<input.length(); i++)
    {
        if(input[i] ==  ' ')
        {
            space[space_count] = i;
            space_count++;
        }
    }
    if(input[0] == 'l')
    {
        for(int i=1; i<space[0]; i++)
        {
            if(isdigit(input[i]))
            {

            }
            else{
                cout << "invalid input" << endl;
            }
        }
        if(isdigit(input[space[0]+1]))
        {
            id1 = true;
            for(int j=space[0]+1; j<space[1]; j++)
            {
                if(isdigit(input[j]))
                {

                }
                else{
                   cout << "invalid input" << endl;
                }
            }

        }
        else if(isupper(input[space[0]+1]))
        {
            name1=true;
           for(int j=space[0]+2; j<space[1]; j++)
            {
                if(islower(input[j]))
                {

                }
                else{
                   cout << "invalid input" << endl;
                }
            }
            for(int k=space[1]+1; k<space[2]; k++)
            {
                if(islower(input[k]))
                {
                    if(input[k] != 'b')
                    {

                    }
                    else{
                        cout << "invalid input" << endl;
                    }
                }
                else {
                    cout << "invalid input" << endl;
                }
            }
        }
        else{
            cout << "invalid input" << endl;
        }

    }
    else{
        cout << "invalid input" << endl;
    }



    system("pause");
    return 0;
}
