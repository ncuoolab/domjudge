#include<iostream>

using namespace std;


int main(){
    string s1,s2;
    char c;
    string out;
    bool ck1,ck2,ck3,ck4,ck5;
    cin >> c;
    if(c == 'l'){
        out="level l";
        ck1=true;
    }
    else{
        out="invalid input";
        ck1=false;
    }
    cin >> s1;
    out=out+s1;

    cin >> s1;

    if(ck1&&s1[0]<='9'&&'0'<=s1[0]){
        out=out+"\ncid "+s1;
        ck2=true;
    }
    else if(ck1){
        out=out+"\nFirstName "+s1;
        cin >> s2;
        out=out+"\nLastName "+s2;
        ck2=true;
    }
    else{
        out="invalid input";
        ck2=false;
    }

    cin >> c;
    if(ck2&&c == 'b'){
        out=out+"\nbattle b";
        ck3=true;
    }
    else{
        out="invalid input";
        ck3=false;
    }
    cin >> s1;
    if(ck3&&s1[0]<='9'&&'0'<=s1[0]){
        out=out+"\ncid "+s1;
    }
    else if(ck3){
        out=out+"\nFirstName "+s1;
        cin>>s2;
        out=out+"\nLastName "+s2;
    }
    cout<<out<<endl;

    return 0;

}


