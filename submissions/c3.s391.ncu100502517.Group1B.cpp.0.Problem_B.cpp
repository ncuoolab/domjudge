#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

string a[6];
int total = 0;
bool check = true;


void Stmt(){
    char fa;
    string input, combine;
    int cid;
    cin >> fa;
    if(fa == 'l'){
        cin >> input;
        string combine = fa + input;
        a[total++] = "level "+combine;
        //cout << a[0] << endl;
    }else if(fa == 'b'){
        //cin >> input;
        combine = fa;
        a[total++] = "battle "+combine;
        //cout << a[total-1] << endl;
    }else{
        check = false;
        cin >> input;
        string combine = fa + input;
        a[total++] = combine;
    }

    cin >> fa;
    cin >> input;
    combine = fa+input;

    if(fa=='0' ||fa=='1' ||fa=='2' ||fa=='3' ||fa=='4' ||fa=='5' ||fa=='6' ||fa=='7' ||fa=='8' ||fa=='9'){
        a[total++] = "cid "+ combine;
        //cout << a[total-1] << endl;
    }else{
        a[total++] = "FirstName " + combine;
        cin >> input;
        a[total++] = "LastName " + input;
        //cout << a[total-2] << endl;
        //cout << a[total-1] << endl;
    }
}

int main(){
    Stmt();
    Stmt();
    if(check == true){
        for(int i = 0; i < total; i++){
            cout << a[i] << endl;
        }
    }else{
        cout << "invalid input";
    }

    system("pause");
    return 0;
}

