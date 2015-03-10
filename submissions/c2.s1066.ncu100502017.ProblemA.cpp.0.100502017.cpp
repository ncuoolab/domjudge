#include<iostream>
#include<string>

using namespace std;

int main(){
    string s,r="";
    int ST=0;
    char c;
    bool running;
    //while(running){
    getline(cin,s);
    s=s+" ";
    for(int i=0;i<s.length();i++){
            //cout<<ST;
        c=s[i];
        if((int)c>=97&&(int)c<=122&&ST==0){
                r=r+"id "+c;
                ST=1;

        }
        else if((int)c>=97&&(int)c<=122&&ST==1){
                r=r+c;

        }
        else if((c==' '||c=='\n')&&ST==1){
                r=r+"\n";
                ST=2;
        }
        else if(c=='='&&ST==2){
            r=r+"assign =\n";
            ST=3;
        }
        else if((int)c>=48&&(int)c<=57&&ST==3){
                r=r+"inum "+c;
                ST=4;
        }
        else if((int)c>=48&&(int)c<=57&&ST==4){
                r=r+c;
        }
        else if((c==' '||c=='\n')&&ST==4){
                cout<<r;
                break;
        }
        else if((int)c>=97&&(int)c<=122&&ST==3){
                r=r+"id "+c;
                ST=5;
        }
        else if((int)c>=97&&(int)c<=122&&ST==5){
                r=r+c;
        }
        else if((c==' '||c=='\n')&&ST==5){
                cout<<r;
                break;
        }
        else if(c==' '){

        }
        else{
            cout << "valid input";
            break;
        }

    }
    //}
    //
    return 0;
}
