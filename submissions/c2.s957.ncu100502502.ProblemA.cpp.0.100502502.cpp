#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;
bool id(string s);
bool Val(string s);
bool inum(string s);
string a[3];
string b[3];
int count = 0;
int main(){
    string s;
    cin >> s;
    /*char c= '0';
    char d = '9';
    int aa = c;
    int bb =d;
    cout << aa <<" "<<bb;*/
    if(id(s)){
        cin >> s;
        if(s == "="){
            a[count] = "assign";
            b[count] = "=";
            count++;
            cin >> s;
            if(Val(s)){
                for(int i=0; i<count; i++)
                    cout << a[i] <<" " << b[i]<<endl;
            }
            else{
                cout << "valid input"<<endl;
            }
        }
        else{
            cout << "valid input" << endl;
        }
    }
    else{
        cout << "valid input"<<endl;
    }
    system("pause");
    return 0;
}
bool id(string s){
    //bool on = true;
    int t= s[0];
    if(t>=97 && t<=122 &&s.length()==1){
        a[count] = "id";
        b[count] = s;
        count++;
        return true;
    }
    else
        return false;
}
bool Val(string s){
    if(id(s))
        return true;
    else if(inum(s))
        return true;
    else
        return false;
}
bool inum(string s){
    int t;
    bool on = true;
    for(int i=0; i<s.length(); i++){
        t = s[i];
        if(t>=48 && t<=57){}
        else{
            on = false;
            break;
        }
    }
    if(on == true)
        a[count] = "inum";
        b[count] = s;
        count++;
    return on;
}
