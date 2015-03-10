#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

string answer[3];
int total = 0;
bool checkup = true;

bool check(string a){
    if(a.length() >1){
        return false;
    }else{
        char p = a[0];
        if(p >= 97 && p <= 122){
            return true;
        }else{
            return false;
        }
    }

}

void Stmt(){
    string a;
    int input;
    cin >> a;
    if(check(a)){
        answer[total++] = "id " + a;
    }else{
        checkup = false;
    }
    cin >> a;
    if(a == "="){
        answer[total++] = "assign " + a;
    }else{
        checkup =false;
    }
    cin >> a;
    for(int i = 0; i < a.length(); i++){
        if(a[i] == '0' ||a[i] == '1'||a[i] == '2'||a[i] == '3'||a[i] == '4'||a[i] == '5'||a[i] == '6'||a[i] == '7'||a[i] == '8'||a[i] == '9'){
        }else{
            checkup = false;
        }
    }
    answer[total++] = "inum " + a;
}

int main(){
    Stmt();
    if(checkup){
        for(int i = 0; i < 3; i++){
            cout << answer[i] << endl;
        }
    }else{
        cout << "valid input" << endl;
    }
    system("pause");
    return 0;
}

