#include<iostream>
#include<cstring>
using namespace std;
int main(){
    string id,ass,Val;
    cin>>id>>ass>>Val;
    if(id.size()==1&&(int)id[0]>=97&&(int)id[0]<=122){
        if(ass.size()==1&&(int)ass[0]==61){
            bool Valcheck=true;
            for(int i=0;i<Val.size();i++){
                if((int)Val[i]>=48&&(int)Val[i]<=57){
                    Valcheck=true;
                }
                else{
                    Valcheck=false;
                    break;
                }
            }
            if(Valcheck==true&&Val.size()>0){
                cout<<"id "<<id<<endl;
                cout<<"assign "<<ass<<endl;
                cout<<"inum "<<Val<<endl;
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
