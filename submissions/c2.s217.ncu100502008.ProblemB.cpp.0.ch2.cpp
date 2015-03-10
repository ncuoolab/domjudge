#include <string>
#include <iostream>
using namespace std;

int main() {
 //bool correct=true;
     string in;
     string out="";
     string str="";
     bool finish=false;
     bool nl=false;
     getline(cin,in);
     int count=0,type=0;
     for(int i = 0;i<in.size();i++){
         if(in[i]!=' '){
            if(type==1){
                if(count==1&&(('a'<=in[i]&&in[i]<='o')||('q'<=in[i]&&in[i]<='r')||('t'<=in[i]&&in[i]<='z'))){
                    out=out+"id "+in[i]+"\n";
                    count++;
                }
                else if(count==2&&(in[i]=='"'||in[i]=='\\')){
                    out=out+"quote "+in[i]+"\n";
                    count++;
                }
                else if(count==3&&(in[i]=='"'||in[i]=='\\')){
                    out=out+"string "+str+"\n";
                    out=out+"quote "+in[i]+"\n";
                    count++;
                    finish=true;
                }
                else if(count==3&&(in[i]!='"'&&in[i]!='\\')&&i<(in.size()-1)&&(('a'<=in[i]&&in[i]<='z')||('A'<=in[i]&&in[i]<='Z')||('0'<=in[i]&&in[i]<='9'))){
                    str=str+in[i];
                }
                else if(count==4&&in[i]=='\n'){
                    type=0;
                    nl=true;
                    count=0;
                }
                else{
                    out+="valid input1\n";
                    break;
                }
            }
            else if(type==2){
                if(count==1&&(('a'<=in[i]&&in[i]<='o')||('q'<=in[i]&&in[i]<='r')||('t'<=in[i]&&in[i]<='z'))){
                    out=out+"id "+in[i]+"\n";
                    count++;
                    finish=true;
                }
                else{
                    out="valid input\n";
                    break;
                }
            }
         }
         if(in[i]!=' '&&type==0){
             if(count==0&&in[i]=='s'){
                out=out+"strdcl s\n";
                count++;
                type=1;
            }
            else if(count==0&&in[i]=='p'){
                out=out+"print p\n";
                count++;
                type=2;
            }else if(nl&&in[i]=='\n'){
                //do nothing
            }
            else{
                out="valid input\n";
                break;
            }
         }
        if(i==in.size()-1&&!finish){
            out="valid input\n";
            break;
        }
     }
     cout<<out;
 return 0;
}
