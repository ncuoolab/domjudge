#include<iostream>
#include<cstdlib>
#include<string>
#include<string.h>
using namespace std;
string result="";
int numTest=-1;
int inumTest=-1;
int RE_id(char msg[],int startId){
    bool cStart,inSpace=false;
    numTest=-1;
    int i;
    for(i=startId;i<strlen(msg);i++){
        int num=msg[i]-'a';
        if((num>=0&&num<=25)||(num>=-32&&num<=-7)||(num==-2)){
            if(inSpace)
                return -1;//錯誤訊息
            cStart=true;
        }
        else if(num==-57||num==-56){//遇到右括號要回傳

            return i-1;
        }
        else if(num==-65){
            if(cStart)
                inSpace=true;
            numTest=-65;
        }
        else{
            return -1;//錯誤訊息
        }
    }
}
int RE_inum(char msg[], int startId){
     bool cStart,inSpace=false;
    inumTest=-1;
    int i;
    for(i=startId;i<strlen(msg);i++){
        int num=msg[i]-'a';
        if((num>=-49&&num<=-40)){
            if(inSpace)
                return -1;//錯誤訊息
            cStart=true;
        }//0~9
        else if(num==-56){//遇到右括號要回傳
            return i-1;
        }
        else if(num==-65){
            if(cStart){
                inSpace=true;
            }
            inumTest=-65;
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
        result="invalid input";
    }

}
void RE_lparenthesie(char msg){
    int num=msg-'a';
    if(num==-57){
        string temp(1,msg);
        result+="lparenthesis "+temp+"\n";
    }
    else{
        result="invalid input";
    }
}
void RE_rparenthesie(char msg){
    int num=msg-'a';
    if(num==-56){
        string temp(1,msg);
        result+="rparenthesis "+temp+"\n";
    }
    else{
        result="invalid input";
    }
}
void Para(char msg[], int startId){
    string temp;
    int id=RE_id(msg,startId);
    int inum=RE_inum(msg,startId);
    if(id!=-1){
        if(numTest==-65)
            return;
        else
            result+="id "+temp.assign(msg,startId,id-startId+1)+"\n";
    }
    else if(inum!=-1){
        if(inumTest==-65)
            return;
        else
            result+="inum "+temp.assign(msg,startId,inum-startId+1)+"\n";
    }
    else if(msg[startId+1]==NULL){//空字串
        return;
    }
    else{
        result="invalid input";
    }

}
void Func(char msg[], int startId){
    RE_lparenthesie(msg[startId]);
    int num=msg[startId+1]-'a';
    if(num==-65)
            startId++;
    if(result!="invalid input"){
        Para(msg,startId+1);
    }
    else{
        return;
    }
    if(result!="invalid input"){
        RE_rparenthesie(msg[strlen(msg)-1]);
    }
    else{result="invalid input";
        return;
    }
}
void Stmt(char msg[]){
    if(strlen(msg)<=1){
        result="invalid input";
        return;
    }
    string temp;
    int id=RE_id(msg,0);
    if(id!=-1){
        result+="id "+temp.assign(msg,0,id+1)+"\n";
    }
    else{
        result="invalid input";
        return;
    }
    if(result!="invalid input"){
        int num=msg[id+1]-'a';
        if(num==-65)
            Func(msg,id+2);
        else
            Func(msg,id+1);
    }
    else{
        return;
    }
}
int main(){
    const int size=100000;
    char msg[size] ;
    cin.getline(msg,size);
    Stmt(msg);
    cout <<result << endl;
    return 0;
}
