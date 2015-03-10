#include<cstdlib>
#include<iostream>
#include<string>
#include<string.h>
using namespace std;
string result="";//output message
string RE_strdcl(char temp){
    string msg;
    string s_temp(1,temp);//字元轉字串輸出
    int num=temp-'a';
    if(num==18){//strdcl : s
        msg="strdcl "+s_temp+"\n";
    }
    else{//錯誤回傳
        result="valid input";
        return "";
    }
    return msg;
}
string RE_id(char temp){
    string msg;
    string s_temp(1,temp);//字元轉字串輸出
    int num=temp-'a';
    if(((num>=0)&&(num<=14))||(num==16)||(num==17)||((num>=19)&&(num<=25))){// id
        msg="id "+s_temp+"\n";
    }
    else{//錯誤回傳
        result="valid input";
        return "";
    }
    return msg;
}
string RE_quoto(char temp){
    string msg;
    string s_temp(1,temp);//字元轉字串輸出
    int num=temp-'a';
    if(num==-63){// quote : "
        msg="quoto "+s_temp+"\n";
    }
    else{//錯誤回傳
        result="valid input";
        return "";
    }
    return msg;
}
string RE_string(char temp){
    string msg;
    string s_temp(1,temp);//字元轉字串輸出
    int num=temp-'a';
    if(num==18){//strdcl : s
        msg="strdcl "+s_temp+"\n";
    }
    else{//錯誤回傳
        result="valid input";
        return "";
    }
    return msg;
}
string RE_print(char temp){
    string msg;
    string s_temp(1,temp);//字元轉字串輸出
    int num=temp-'a';
    if(num==15){// print : p
        msg="print "+s_temp+"\n";
    }
    else{//錯誤回傳
        result="valid input";
        return "";
    }
    return msg;
}
string RE_space(char temp){
    string msg;
    string s_temp(1,temp);//字元轉字串輸出
    int num=temp-'a';
    if(num==num)
        return "";
    else{//錯誤回傳
        result="valid input";
        return "";
    }
    return msg;
}
int RE_string(char msg[],int start_str){//判斷字串是否符合規則
    int length=strlen(msg);
    int i;
    for(i=start_str;i<length;i++){
        int num=msg[i]-'a';
        if((msg[start_str]-'a')==-63){//空字串的情形
            return start_str-1;
        }
        else if((num>=0)&&(num<=25)){}//a~z
        else if((num>=-32)&&(num<=-7)){}//A~Z
        else if((num>=-49)&&(num<=-40)){}//0~9
        else if(num==-63){//遇到右quote
            return i-1;//回傳string最後一個index
        }
        else{
            return -1;//錯誤訊息
        }
    }
}
void Stmt(char msg[]){
    if(strlen(msg)<=2){
        result="valid input";
        return;
    }
    result+=RE_print(msg[0]);
    if(result!="valid input")
        result+=RE_space(msg[1]);
    else
        return;
    if(result!="valid input")
        result+=RE_id(msg[2]);
    else
        return;
}
void Astring(char msg[],int i){
    string temp;
    result+=RE_quoto(msg[i]);
    if(result!="valid input"){
        int end_str=RE_string(msg,i+1);
        if(end_str==-1){
            result="valid input";
            return;
        }
        else if(end_str==i){
            result+="string \n";
        }
        else{
            result+="string "+temp.assign(msg,i+1,end_str-i)+"\n";
        }
        i=end_str+1;
        result+=RE_quoto(msg[i]);
    }
    else
        return;

}
void Dcl(char msg[]){
    if(strlen(msg)<=5){
        result="valid input";
        return;
    }
    result+=RE_strdcl(msg[0]);
    if(result!="valid input")
        result+=RE_space(msg[1]);
    else
        return;
    if(result!="valid input")
        result+=RE_id(msg[2]);
    else
        return;
    if(result!="valid input")
        result+=RE_space(msg[3]);
    else
        return;
    Astring(msg,4);
}
int main(){
    const int arraySize1=30;
    char msg1[arraySize1];
    cin.getline(msg1,arraySize1);//讀到Enter鍵即結束
    Dcl(msg1);
    if(result!="valid input"){
        const int arraySize2=10;
        char msg2[arraySize2];
        cin.getline(msg2,arraySize2);//讀到Enter鍵即結束
        Stmt(msg2);
    }
    cout << result << endl;
    return 0;
}
