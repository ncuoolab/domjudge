#include<iostream>
#include<cstdlib>
#include<string>
#include<string.h>
using namespace std;
string result="";
int RE_id(char msg[],int startId){
    string temp="";
    int i;
    for(i=startId;i<strlen(msg);i++){
        int num=msg[i]-'a';
        if((num>=0&&num<=25)||(num>=-32&&num<=-7)||(num==-2)){
            continue;
        }
        else if(num==-57||num==-56){//遇到右括號要回傳
            return i-1;
        }
        else{
            return -1;//錯誤訊息
        }
    }
}
int RE_inum(char msg[], int startId){
    string temp="";
    int i;
    for(i=startId;i<strlen(msg);i++){
        int num=msg[i]-'a';
        if((num>=-49&&num<=-40)){
            continue;
        }//0~9
        else if(num==-56){//遇到右括號要回傳
            return i-1;
        }
        else{
            return -1;//錯誤訊息
        }
    }
}
void RE_space(char msg){
    int num=msg-'a';
    if(num==-65){
        return;
    }
    else{
        result="invalide input??";
    }

}
void RE_lparenthesie(char msg){
    int num=msg-'a';
    if(num==-57){
        string temp(1,msg);
        result+="lparenthesis "+temp+"\n";
    }
    else{
        result="invalide input";
    }
}
void RE_rparenthesie(char msg){
    int num=msg-'a';
    if(num==-56){
        string temp(1,msg);
        result+="rparenthesis "+temp+"\n";
    }
    else{
        result="invalide input";
    }
}
void Para(char msg[], int startId){
    string temp;
    int id=RE_id(msg,startId);
    int inum=RE_inum(msg,startId);
   /* cout << "id : " <<id <<endl;
    cout << "inum : " <<inum <<endl;*/
    if((id!=-1)&&(id!=startId)){
        result+="id "+temp.assign(msg,startId,id-startId+1)+"\n";
    }
    else if((inum!=-1)&&(id!=startId)){
        result+="id "+temp.assign(msg,startId,inum-startId+1)+"\n";
    }
    else if(msg[startId+1]==NULL){//空字串
        result+="$\n";
    }
    else{
        result="invalide input";
    }

}
void Func(char msg[], int startId){
    RE_lparenthesie(msg[startId]);
    if(result!="invalide input"){
        Para(msg,startId+1);
    }
    else{
        return;
    }
    if(result!="invalide input"){
        RE_rparenthesie(msg[strlen(msg)-1]);
    }
    else{
        return;
    }
}
void Stmt(char msg[]){
    if(strlen(msg)<=1){
        result="invalide input";
        return;
    }
    string temp;
    int id=RE_id(msg,0);
    if(id!=-1){
        result+="id "+temp.assign(msg,0,id+1)+"\n";
    }

    else{
        return;
    }
    if(result!="invalide input"){
        Func(msg,id+1);
    }
    else{
        return;
    }
}
int main(){
    const int size=20;
    char msg[size] ;
    cin.getline(msg,size);
    Stmt(msg);
    cout <<result << endl;
    return 0;
}
