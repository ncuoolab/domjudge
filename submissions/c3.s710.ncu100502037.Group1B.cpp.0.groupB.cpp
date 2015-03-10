#include <stdio.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include <algorithm>//swap
#include <ctype.h>

using namespace std;

//int Scan();
//void Parse();

char level_marked, battle;
char ch[100];
string firstName, lastName, firstName2, lastName2;
int level, bNum, cid;


int is_another_id = 0;

int main() {

    cid = 0;
    //getline(cin, line ,'\n');
    cin>> level_marked;
    if(level_marked == 'l'){
        cin>> level;
        cin>> firstName;
        cin>> lastName;

        cin>> battle;
        if(battle =='b'){
            cin>> ch[0];
            cin>> firstName2;

            if (isdigit(ch[0])){

                //cout << "I am digit"<< endl;
                firstName2 = ch[0]+firstName2;
                cid = 1;
            }
            else{
                firstName2 = ch[0]+firstName2;
                cin>> lastName2;

            }

            bNum = 1;
        }
        else{
            cout<<"invalid input" << endl;
            return 0;
        }

        cout<<"level l" << level << endl;
        cout<<"FirstName "<< firstName  << endl;
        cout<<"LastName "<< lastName  << endl;

        cout<<"battle b"  << endl;

        if(cid == 1){
            cout<<"cid "<< firstName2  << endl;
            return 0;

        }
        else if(cid == 0){
            cout<<"FirstName "<< firstName2  << endl;
            cout<<"LastName "<< lastName2  << endl;
            return 0;
        }




    }
    else{
        cout<<"invalid input" << endl;
        return 0;

    }

    return 0;
}

