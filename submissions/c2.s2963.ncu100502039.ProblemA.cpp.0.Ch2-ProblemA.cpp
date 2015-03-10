#include<cstdlib>
#include<iostream>

#include<string.h>
using namespace std;

void Stmt();
void Re_id();
void IsSpace();
void Re_assign();
void Val();
void Re_inum();

const int size = 30;
char msg[size];
string result = "";
int index = 0;

int main(){
    cin.getline(msg,size);
    Stmt();
    cout << result;
    return 0;
}
void Stmt(){
    if(strlen(msg)<1){
        result = "invalid input";
        return;
    }
    Re_id();
    if(result!="invalid input"){
        IsSpace();
        Re_assign();
    }
    if(result!="invalid input"){
        IsSpace();
        Val();
    }

}
void Re_id(){
    int num = msg[index]-0;
    if(num>=97 && num<=122){
        string temp;
        result += "id " + temp.assign(msg,index,1);
        index++;
    }
    else
        result = "invalid input";
}
void IsSpace(){
    int num = msg[index]-0;
    while(num == 32){
        index++;
        num = msg[index]-0;
    }
}
void Re_assign(){
    int num = msg[index]-0;
    if(num == 61){
        string temp;
        result += "\nassign " + temp.assign(msg,index,1);
        index++;
    }
    else
       result = "invalid input";
}
void Val(){
    int num = msg[index]-0;
    if(num>=97 && num<=122){
        string temp;
        result += "\nid " + temp.assign(msg,index,1);
        return;
    }
    if(num>=48 && num<=57){
        int tempID = index;
        Re_inum();
        string temp;
        result+="\ninum "+temp.assign(msg,tempID,index-tempID);
    }
    else
        result = "invalid input";
    if(index != strlen(msg))
        result = "invalid input";
}
void Re_inum(){
    int i;
    for(i=index;i<strlen(msg);i++){
        int num = msg[index]-0;
        if(num>=48 && num<=57){
            index++;
        }
        else
            break;
    }
}

