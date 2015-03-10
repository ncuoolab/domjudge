#include<iostream>
#include<cstring>
using namespace std;
int CID(string);
int LEVEL(string);
int Firstname(string);
int Lastname(string);
int main(){

    string s1,s2;
    getline(cin,s1);
    string level;
    string firstname1,lastname1,firstname2,lastname2,cid1,cid2;
    string battle;

    int b1,b2,b3,b4,b5;
    b1=s1.find(' ',0);
    b2=s1.find(' ',b1+1);
    b5=s1.find(' ',b2+1);
    level.assign(s1,0,b1);
    //cout<<level<<endl;

    if(b5>=0){
        cout<<"invalid input";

    }
    else {
    if(LEVEL(level)==0){
        getline(cin,s2);//s2
        b3=s2.find(' ',0);
        b4=s2.find(' ',b3+1);
        if(b2==-1){//l100 9527
            cid1.assign(s1,b1+1,s1.size()-b1-1);

            //cout<<cid1<<endl;

            if(CID(cid1)==0){
                battle.assign(s2,0,1);
                //cout<<battle<<endl;
                if(battle[0]=='b'){
                    if(b4==-1){//b 1234
                        cid2.assign(s2,b3+1,s2.size()-b3-1);

                        //cout<<cid2<<endl;

                        if(CID(cid2)==0){
                            cout<<"level "<<level<<endl;
                            cout<<"cid "<<cid1<<endl;
                            cout<<"battle "<<battle<<endl;
                            cout<<"cid "<<cid2<<endl;
                        }
                        else{
                            cout<<"invalid input";
                        }
                    }
                    else{
                        firstname2.assign(s2,b3+1,b4-b3-1);
                        lastname2.assign(s2,b4+1,s2.size()-b4-1);

                        //cout<<firstname2<<" "<<lastname2<<endl;


                        if(Firstname(firstname2)==0)
                        {
                            if(Lastname(lastname2)==0){
                                cout<<"level "<<level<<endl;
                                cout<<"cid "<<cid1<<endl;
                                cout<<"battle "<<battle<<endl;
                                cout<<"FirstName "<<firstname2<<endl;
                                cout<<"LastName "<<lastname2<<endl;
                            }
                            else{
                                cout<<"invalid input";
                            }
                        }
                        else{
                            cout<<"invalid input";
                        }
                    }
                }
                else{
                    cout<<"invalid input";
                }
            }
            else {
                cout<<"invalid input";
            }
        }
        else{
            firstname1.assign(s1,b1+1,b2-b1-1);
            lastname1.assign(s1,b2+1,s1.size()-b2-1);

            //cout<<firstname1<<endl;

            if(Firstname(firstname1)==0){
                if(Lastname(lastname2)==0){
                    //cout<<s2<<endl;
                    battle.assign(s2,0,1);
                    //cout<<battle<<endl;
                    if(battle[0]=='b'){
                            //cout<<b4;
                        if(b4==-1){
                             cid2.assign(s2,b3+1,s2.size()-b3-1);

                             //cout<<cid2<<endl;

                             if(CID(cid2)==0){
                                cout<<"level "<<level<<endl;
                                cout<<"FirstName "<<firstname1<<endl;
                                cout<<"LastName "<<lastname1<<endl;
                                cout<<"battle "<<battle<<endl;
                                cout<<"cid "<<cid2<<endl;
                             }
                             else{
                                cout<<"invalid input";
                             }
                        }
                        else{
                            firstname2.assign(s2,b3+1,b4-b3-1);
                            lastname2.assign(s2,b4+1,s2.size()-b4-1);

                            //cout<<firstname2<<" "<<lastname2<<endl;

                            if(Firstname(firstname2)==0)
                            {
                                if(Lastname(lastname2)==0){
                                    cout<<"level "<<level<<endl;
                                    cout<<"FirstName "<<firstname1<<endl;
                                    cout<<"LastName "<<lastname1<<endl;
                                    cout<<"battle "<<battle<<endl;
                                    cout<<"FirstName "<<firstname2<<endl;
                                    cout<<"LastName "<<lastname2<<endl;
                                }
                                else{
                                    cout<<"invalid input";
                                }
                            }
                            else{
                                cout<<"invalid input";
                            }
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
            else {
                cout<<"invalid input";
            }
        }
    }
    else{
        cout<<"invalid input";
    }
    }
}
int LEVEL(string s){
    int t=0;
    if(s.size()==1){
        t=1;
    }
    else if(s[0]=='l'){
        for(int i=1;i<s.size();i++){
        if((int)s[i]>=48&&(int)s[i]<=57){
            t=0;
        }
        else {
            t=1;
            break;
        }
    }
    }
    else{
        t=1;
    }
    return t;
}
int Firstname(string s){
    int t=0;
    if((int)s[0]>=65&&(int)s[0]<=90){
        for(int i=1;i<s.size();i++){
            if((int)s[i]>=97&&(int)s[i]<=122){
                t=0;
            }
            else{
                t=1;
                break;
            }
        }
    }
    else{
        t=1;
    }

    return t;
}
int Lastname(string s){
    int t=0;
    for(int i=0;i<s.size();i++){
        if((int)s[i]==97||((int)s[i]>=99&&(int)s[i]<=122)){
        }
        else{
            t=1;
            break;
        }
    }
    return t;
}
int CID(string s){
    int t=0;
    for(int i=0;i<s.size();i++){
        if((int)s[i]>=48&&(int)s[i]<=57){
        }
        else {
            t=1;
            break;
        }
    }
    return t;
}
