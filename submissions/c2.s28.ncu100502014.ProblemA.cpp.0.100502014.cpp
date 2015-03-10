#include<iostream>
#include<cstdlib>

using namespace std;



int main() {
    char a;
    cin >> a;
    if((a-'a')>=0 && (a-'a')<26) {
        char b;
        cin >> b;
        if(b=='=') {
            char c;
            cin >> c;
            if((c-'a')>=0 && (c-'a')<26) {
                cout << "id " << a << endl;
                cout << "assign " << b << endl;
                cout << "id " << c;
            }
            else if((c-'0')>=0 && (c-'0')<10) {
                string d;
                cin >> d;
                bool flag = true;
                for(int i=0;i<d.length();i++) {
                    if((d[i]-'0')<0 || (d[i]-'0')>9) {
                        cout << "valid input";
                        flag = false;
                        break;
                    }
                }
                if(flag) {
                    cout << "id " << a << endl;
                    cout << "assign " << b << endl;
                    cout << "inum " << c << d;
                }
            }
            else {
                cout << "valid input";
            }
        }
        else {
            cout << "valid input";
        }
    }
    else {
        cout << "valid input";
    }

    return 0;
}
 //|| (s[0]-' ')==0
