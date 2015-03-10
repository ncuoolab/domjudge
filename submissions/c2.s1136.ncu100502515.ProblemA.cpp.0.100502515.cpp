#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

bool checkStmt(string);
int main() {
    string input, adjust, stmt, id, a, n;
    getline(cin,input);
    for(int i=0; i<input.size(); i++) {
        if(input[i] == ' ')
            continue;
        adjust += input[i];
    }
    for(int i=0; i<adjust.size(); i++) {
        if(97 <= (int)adjust[i] && (int)adjust[i] <= 122) {
            stmt += "i";
            id = id + adjust[i] + " ";
        }else if((int)adjust[i] == 61) {
            stmt += "a";
            a = a + adjust[i] + " ";
        }else if(48 <= (int)adjust[i] && (int)adjust[i] <= 57) {
            stmt += "n";
            n += adjust[i];
        }
            else{
                cout << "valid input";
                system("pause");
                return 0;
            }
    }
    if(checkStmt(stmt) == true) {
        cout << "id "    << id << endl
             << "assign " << a  << endl
             << "inum "   << n  << endl;
    }else {
        cout << "valid input";
    }

    system("pause");
    return 0;
}

bool checkStmt(string stmt) {
    if(stmt[0] != 'i') {
        return false;
    } else if(stmt[1] != 'a') {
        return false;
    } else if(stmt[2] == 'i' && stmt[3] != '\0') {
        return false;
    } else if(stmt[2] == 'n'){
        for(int i = 3; i < stmt.size(); i++) {
            if(stmt[i] != 'n') {
                return false;
            }
        }
        return true;
    }
}
