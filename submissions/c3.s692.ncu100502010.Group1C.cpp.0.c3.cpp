#include <iostream>
#include <sstream>
using namespace std;

int main(){
    string in="";
    string temp="";
    string out="";
    int count=0;
    int type=0;
    string str;
    string sstr;
    while(getline(cin,temp)){
        in=in+'&'+temp;
    }
    for(int i=0;i<in.size();i++){
        if(count==0&&in[i]=='&'){
        }
        else if(count==0&&(('A'<=in[i]&&in[i]<='Z')||('a'<=in[i]&&in[i]<='z')||in[i]=='_')){
            str=str+in[i];
        }
       else if(count==0&&(in[i]==' '||in[i]=='\r'||in[i]=='\n')){
            out=out+"id "+str+"\n";
            count++;
        }
        else if(count==0&&in[i]=='('){
            out=out+"id "+str+"\n";
            out=out+"lparenthesis "+in[i]+"\n";
            count+=2;
        }
        else if(count==1&&(in[i]==' '||in[i]=='\r'||in[i]=='\n')){
        }
        else if(count==1&&in[i]=='('){
            out=out+"lparenthesis "+in[i]+"\n";
            count++;
        }
        else if(count==2&&(('A'<=in[i]&&in[i]<='Z')||('a'<=in[i]&&in[i]<='z')||in[i]=='_')){
            sstr=sstr+in[i];
            type=1;
            count++;
        }
        else if(count==2&&'0'<=in[i]&&in[i]<='9'){
            sstr=sstr+in[i];
            type=2;
            count++;
        }
        else if(count==2&&in[i]==')'){
            out=out+"rparenthesis "+in[i]+"\n";
            count++;
        }
        else if(count==3&&type==1&&(('A'<=in[i]&&in[i]<='Z')||('a'<=in[i]&&in[i]<='z')||in[i]=='_')){
            sstr=sstr+in[i];
        }
        else if(count==3&&type==2&&'0'<=in[i]&&in[i]<='9'){
            sstr=sstr+in[i];
        }
        else if(count==3&&in[i]==')'){
             if(type==1){
                out=out+"id "+sstr+"\n";
             }
             else{
                out=out+"inum "+sstr+"\n";
             }
             out=out+"rparenthesis "+in[i]+"\n";
            count++;
        }
        else{
            out+="invalid output\n";
            break;
        }
    }
    cout<<out<<endl;
    return 0;
}
