#include <iostream>
#include <cstdlib>
#include <cctype>
#include <string>

using namespace std;

char input[100];
int position1=0, position2=0, stop=0;
int temp;
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
    }
    for(int j=0; j<100; j++)
    {
        if(input[j] == ')')
        {
            position2 = j;

        }
    }
   // cout << input[3] << " " << input[7];

    if(position1==0 || position2 ==0)
    {
        cout << "invalid input" << endl;
        final = false;
    }

    if(position2==position1+1)
    {
        no = true;
    }

    temp = position1+1;
    //cout << temp;
    //cout << position2 << " " << position1;

    for(int i=0; i<position1; i++)
        {
            //cout << input[i];
            if(isalpha(input[i]))
            {

            }
            else if(input[i] == '_')
            {

            }
            else
            {
                cout << "invalid input" << endl;
                final = false;
            }
        }

        for(int j=temp; j<position2; j++)
        {
            //cout << input[i];
            if(isalpha(input[j]))
            {
                id = true;
            }
            else if(input[j]=='_')
            {
                id = true;
            }
            else if(isdigit(input[j]))
            {
                inum = true;
                //cout << input[j];
            }
            else
            {
                cout << "invalid input" << endl;
                final = false;
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
