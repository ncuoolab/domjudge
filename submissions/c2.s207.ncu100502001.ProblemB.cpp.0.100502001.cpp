#include<cstdlib>
#include<iostream>
#include<string>
#include<string.h>
using namespace std;
string result="";//output message
string RE_strdcl(char temp){
    string msg;
    string s_temp(1,temp);//�r����r���X
    int num=temp-'a';
    if(num==18){//strdcl : s
        msg="strdcl "+s_temp+"\n";
    }
    else{//���~�^��
        result="valid input";
        return "";
    }
    return msg;
}
string RE_id(char temp){
    string msg;
    string s_temp(1,temp);//�r����r���X
    int num=temp-'a';
    if(((num>=0)&&(num<=14))||(num==16)||(num==17)||((num>=19)&&(num<=25))){// id
        msg="id "+s_temp+"\n";
    }
    else{//���~�^��
        result="valid input";
        return "";
    }
    return msg;
}
string RE_quoto(char temp){
    string msg;
    string s_temp(1,temp);//�r����r���X
    int num=temp-'a';
    if(num==-63){// quote : "
        msg="quoto "+s_temp+"\n";
    }
    else{//���~�^��
        result="valid input";
        return "";
    }
    return msg;
}
string RE_string(char temp){
    string msg;
    string s_temp(1,temp);//�r����r���X
    int num=temp-'a';
    if(num==18){//strdcl : s
        msg="strdcl "+s_temp+"\n";
    }
    else{//���~�^��
        result="valid input";
        return "";
    }
    return msg;
}
string RE_print(char temp){
    string msg;
    string s_temp(1,temp);//�r����r���X
    int num=temp-'a';
    if(num==15){// print : p
        msg="print "+s_temp+"\n";
    }
    else{//���~�^��
        result="valid input";
        return "";
    }
    return msg;
}
string RE_space(char temp){
    string msg;
    string s_temp(1,temp);//�r����r���X
    int num=temp-'a';
    if(num==num)
        return "";
    else{//���~�^��
        result="valid input";
        return "";
    }
    return msg;
}
int RE_string(char msg[],int start_str){//�P�_�r��O�_�ŦX�W�h
    int length=strlen(msg);
    int i;
    for(i=start_str;i<length;i++){
        int num=msg[i]-'a';
        if((msg[start_str]-'a')==-63){//�Ŧr�ꪺ����
            return start_str-1;
        }
        else if((num>=0)&&(num<=25)){}//a~z
        else if((num>=-32)&&(num<=-7)){}//A~Z
        else if((num>=-49)&&(num<=-40)){}//0~9
        else if(num==-63){//�J��kquote
            return i-1;//�^��string�̫�@��index
        }
        else{
            return -1;//���~�T��
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
    cin.getline(msg1,arraySize1);//Ū��Enter��Y����
    Dcl(msg1);
    if(result!="valid input"){
        const int arraySize2=10;
        char msg2[arraySize2];
        cin.getline(msg2,arraySize2);//Ū��Enter��Y����
        Stmt(msg2);
    }
    cout << result << endl;
    return 0;
}
