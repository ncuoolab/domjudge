#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;
int r=0;
class  token
{
public:
    token(){}
    string title;
    string ctt;
};

void scanner(string s,int* count,token*t)
{
    string num="";
    string title="";
    for(int i=0;i<s.length();i++)
    {
        (*count)++;
        if(s[i]>='a' &&s[i]<='z'||s[i]>='A'&&s[i]<='Z'||s[i]=='_'){
            if(i==s.length()-1){
                title+=s[i];
                t[*count].ctt=title;
                t[*count].title="id";
            }
            else{
                title+=s[i];
                (*count)--;
            }
        }
        else if(s[i]<='9'&&s[i]>='0'){
            if(i==s.length()-1){
                num+=s[i];
                t[*count].ctt=num;
                t[*count].title="inum";
            }
            else{
                num+=s[i];
                (*count)--;
            }
        }
        else if(s[i]=='('){
            r++;
            if(title!=""){
                t[*count].ctt=title;
                t[*count].title="id";
                title="";
                (*count)++;
            }
            else if(num!=""){
                t[*count].ctt=num;
                t[*count].title="inum";
                (*count)++;
                num="";
            }
            t[*count].ctt="(";
            t[*count].title="lparenthesis";
        }
        else if(s[i]==')'){
            r++;
            if(title!=""){
                t[*count].ctt=title;
                t[*count].title="id";
                (*count)++;
                title="";
            }
            else if(num!=""){
                t[*count].ctt=num;
                t[*count].title="inum";
                (*count)++;
                num="";
            }
            t[*count].ctt=")";
            t[*count].title="rparenthesis";
        }
        else{
            (*count)=-1;
            break;
        }
    }
}

void parser(int*count, token*t){
    if((*count)==-1){
        cout<<"invalid input";
        return;
    }
    if(t[1].title!="id"){
        cout<<"invalid input";
        return;
    }
    if(t[2].title!="lparenthesis" ){
        cout<<"invalid input";
        return;
    }
    if(t[3].title!="id"&&t[3].title!="inum"&&t[3].title!=""&&t[3].title!="rparenthesis"){
        cout<<"invalid input";
        return;
    }
    if(t[4].title!="rparenthesis"&&t[4].title!=""){
        cout<<"invalid input";
        return;
    }
    if(t[5].title!=""){
        cout<<"invalid input";
        return;
    }
    for(int i=1;i<=(*count);i++){
        cout<<t[i].title<<" "<<t[i].ctt;
        if(i<(*count)){
            cout<<endl;
        }
    }
}

int main()
{
    token t[100];
    int count=0;
    string input;
    while(cin>>input){
        scanner(input,&count,t);
    }
    parser(&count,t);
    system("pause");
    return 0;
}
