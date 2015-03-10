#include<iostream>
#include<string>
#include<cstdlib>
#include<stdio.h>
#include<string.h>

using namespace std;

int main(){
    string tex="";
    string id="";
    string as="";
    string inum="";
    bool flag = true;
    while(flag){
        tex="";
        id="";
        as="";
        inum="";
        getline(cin,tex);
        for(int i=0;i<tex.length();i++){
            if(flag){
                if(i==0){
                    if(tex[i]>='a'&&tex[i]<='z'){
                        id= tex[i];
                        if(tex[i+1]=='='){
                            as="=";
                            i++;
                        }
                        else if (tex[i+1]==' '){
                            i++;
                        }
                        else if (tex[i+1]>='a' &&tex[i+1]<='z'){
                            flag = false;
                        }
                        else{}
                    }
                    else{
                        flag = false;
                    }
                }
                else{
                    if(tex[i]!=' '){
                        if(tex[i]>='a'&&tex[i]<='z'){
                            if(i==tex.length()-1)
                                id=  id + " "+tex[i];
                            else
                                flag = false;
                        }
                        else if(tex[i]>='0'&&tex[i]<='9'){
                            inum = inum+ tex[i];
                        }
                        else if(tex[i]=='='){
                            as ="=";
                        }
                        else{
                            flag = false;
                        }
                    }
                }
            }
            else
                break;
        }
        if(as=="")
            flag = false;
        if(flag){
            cout<<"id "<< id<<endl
                <<"assign "<<as<<endl
                <<"inum "<<inum<<endl;
        }
        else{
            cout<<"valid input!!"<<endl;
        }
    }
    system("pause");
    return 0;
}
