#include <iostream>
#include <sstream>
using namespace std;

int main(){
    string in="";
    string temp="";
    string out="";
    string FN="";
    string LN="";
    int count=0;
    int btype=0;
    string bnum="";
    string bFN="";
    string bLN="";
    string num;
    while(getline(cin,temp)){
        in=in+'&'+temp;
    }
    //getline(cin,in);

    for(int i=0;i<in.size();i++){
            if(count==0&&in[i]=='&'){
            }
            else if(count==0&&in[i]=='l'){
                out=out+"level l";
                count++;
            }
            else if(count==1&&'0'<=in[i]&&in[i]<='9'){
                num=num+in[i];
            }
            else if(count==1&&(in[i]==' ')){
                out=out+num+"\n";
                count++;
            }
            else if(count==2&&'A'<=in[i]&&in[i]<='Z'){
                FN=FN+in[i];
                count++;
            }
            else if(count==3&&'a'<=in[i]&&in[i]<='z'){
                 FN=FN+in[i];
            }
            else if(count==3&&in[i]==' '){
                out=out+"FirstName "+FN+"\n";
                count++;
            }

            else if(count==4&&'a'<=in[i]&&in[i]<='z'){
                LN=LN+in[i];
            }
            else if(count==4&&in[i]==' '){
                //do nothing
            }
            else if(count==4&&in[i]=='&'){
                out=out+"LastName "+LN+"\n";
                count++;
            }
            else if(count==5&&in[i]==' '){
                //do nothing
            }
            else if(count==5&&in[i]=='b'){
                out=out+"battle b\n";
                count++;
            }
            else if(count==6&&in[i]==' '){
                //do nothing
            }
            else if(count==6&&(('0'<=in[i]&&in[i]<='9')||('A'<=in[i]&&in[i]<='Z'))){
                if('0'<=in[i]&&in[i]<='9'){
                    btype=1;
                    bnum=bnum+in[i];
                    count++;
                }
                else if('A'<=in[i]&&in[i]<='Z'){
                    btype=2;
                    bFN=bFN+in[i];
                    count++;
                }
            }
            else if(count==7&&btype==1&&('0'<=in[i]&&in[i]<='9')){
                bnum=bnum+in[i];
                if(i==in.size()-1){
                    out=out+"cid "+bnum+"\n";
                }
            }
            /*else if(count==7&&btype==1&&(in[i]=='\r'||in[i]=='\n'||in[i]=='&'||in[i]=='\0')){
                out=out+"cid "+bnum+"\n";

            }*/
            else if(count==7&&btype==2&&('a'<=in[i]&&in[i]<='z')){
                bFN=bFN+in[i];
            }
             else if(count==7&&btype==2&&in[i]==' '){
                out=out+"Firstame "+bFN+"\n";
                count++;
            }
            else if(count==8&&('a'<=in[i]&&in[i]<='z')){
                bLN=bLN+in[i];
                 if(i==in.size()-1){
                    out=out+"LastName "+bLN+"\n";
                }
            }
            /*else if(count==8&&(in[i]=='\r'||in[i]=='\n'||in[i]=='&'||in[i]=='\0')){
                 out=out+"LastName "+bLN+"\n";
            }*/
            else{
                //cout<<out<<endl;
                out=out+"invalid input\n";
                //break;
            }
    }
    cout<<out;
    return 0;
}
