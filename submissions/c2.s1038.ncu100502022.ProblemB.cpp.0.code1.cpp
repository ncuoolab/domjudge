#include<iostream>
#include<cstring>
using namespace std;
int main(){
    string strdcl,id1,id2,Astring,print,id;
    cin>>strdcl>>id>>print>>id2;
    id1.assign(id,0,1);
    //cout<<id1<<endl;
    Astring.assign(id,1,id.size()-1);
    //cout<<Astring;

    if(strdcl.size()==1&&strdcl=="s"){
        if(id1.size()==1&&((int)id1[0]>=97&&(int)id1[0]<=111)||(int)id1[0]==113||(int)id1[0]==114||((int)id1[0]>=116&&(int)id1[0]<=122)){
            if(Astring[0]=='\"'&&Astring[Astring.size()-1]=='\"'){
                bool strCheck=true;
                for(int i=1;i<Astring.size()-1;i++){
                    if(((int)Astring[i]>=65&&(int)Astring[i]<=90)||((int)Astring[i]>=97&&(int)Astring[i]<=122)||((int)Astring[i]>=48&&(int)Astring[i]<=57)){
                        strCheck=true;
                    }
                    else{
                        strCheck=false;
                    }
                }
                if(strCheck==true){
                    if(print.size()==1&&print=="p"){
                        if(id2.size()==1&&((int)id2[0]>=97&&(int)id2[0]<=111)||(int)id2[0]==113||(int)id2[0]==114||((int)id2[0]>=116&&(int)id2[0]<=122)){
                            cout<<"strdcl "<<strdcl<<endl;
                            cout<<"id "<<id1<<endl;
                            cout<<"quote "<<"\""<<endl;
                            string Astr;
                            Astr.assign(Astring,1,Astring.size()-2);
                            cout<<"string "<<Astr<<endl;
                            cout<<"quote "<<"\""<<endl;
                            cout<<"print "<<print<<endl;
                            cout<<"id "<<id2<<endl;
                        }
                        else{
                            cout<<"invalid input";
                        }
                    }
                    else{
                            cout<<"invalid input";
                    }
                }
                else{
                            cout<<"invalid input";
                }
            }
            else{
                            cout<<"invalid input";
            }
        }
        else{
                            cout<<"invalid input";
        }
    }
    else{
                            cout<<"invalid input";
    }
    return 0;
}
