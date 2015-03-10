#include <iostream>
#include <cstdlib>
#include <sstream>
#include <string>
using namespace std;

int main() {
    int count=0;
    string temp="";
    string in = "";
    string out ="";
    string error ="valid input";
    bool err=false;
    char a;
    char store;

    while(getline(cin, temp))
        in += temp;
    while(count<in.length()) {
        a = in[count];
        if(a=='"') {
            out=out+"quote "+'"'+"\nstring ";
            count++;
            a=in[count];
            while(a!='"') {
                if(a=='\r'||a=='\n'||a=='\t') {
                    err=true;
                    break;
                }
                out=out+a;
                count++;
                a=in[count];
            }
            out=out+"\nquote "+'"'+"\n";
            count++;
        }
        else if(a=='s') {
            out=out+"strdcl s\n";
            count++;
            a=in[count];

            if(a!=' ') {
                err=true;
            }

            count++;
            a=in[count];

            if(a=='s'||a=='p') {
                err=true;
            }

            out=out+"id "+a+"\n";
            store=a;
            count++;
            if(a=='s'||a=='p') {
                err=true;
            }
        }
        else if(a=='p') {
            out=out+"print p\n";
            count++;
            a=in[count];

            if(a!=' ') {
                err=true;
            }

            count++;
            a=in[count];

            if(a!=store) {
                err=true;
            }
            out=out+"id "+a+"\n";
            count++;
        }
        else if(a==' '||a=='\r'||a=='\n'||a=='\t') {
            count++;
        }
        else if(err==true){
            break;
        }
        else {
            err=true;
            break;
        }
    }
    if(err==true) {
        cout<<error;
    }
    else {
        cout<<out;
    }
}
