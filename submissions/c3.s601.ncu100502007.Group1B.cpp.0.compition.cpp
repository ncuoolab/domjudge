#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;


int main(){
    string s1,s2,s3,s5,s6;
    string right;
    string wrong;
    char c1,c2,c4,c5,c6;
    cin >> c1;
    cin >> s1;
    if(c1 == 'l'){
        right="level l"+s1;
    }
    cin >> c2;
    cin >> s2;
    if(c2 == '0'||c2 == '1'||c2 == '2'||c2 == '3'||c2 == '4'||c2 == '5'||c2 == '6'||c2 == '7'||c2 == '8'||c2 == '9'){
        wrong="invalid input";
    }
    else{
        right=right+"\nFirstName "+c2+s2;
    }
    cin >> s3;
    right=right+"\nLastName "+s3;
    cin >> c4;
    if(c4 == 'b'){
        right=right+"\nbattle b";
    }
    else{
        wrong="invalid input";
    }
    cin >> c5;
    cin >> s5;
    if(c5 == '0'||c5 == '1'||c5 == '2'||c5 == '3'||c5 == '4'||c5 == '5'||c5 == '6'||c5 == '7'||c5 == '8'||c5 == '9'){
        right=right+"\ncid "+c5+s5;
    }
    else{
        right=right+"\nFirstName "+c5+s5;
        cin>>s6;
        right=right+"\nLastName "+s6;
    }
    if(wrong == ""){
        cout<<right;
    }
    else{
        cout<<wrong;
    }


    system("pause");
    return 0;

}


