#include<cstdlib>
#include<iomanip>
#include<string>
#include<iostream>
using namespace std;

int main(){
	char t;
	int state=0;
	int level;
	string s="",r="";
	bool Dcl=true;
	bool over=false;
	while(!over){
		//cout<<"here!!";
		getline(cin,s);
		s=s+" ";
		//cout<<"here2!!";
		for(int i=0;i<s.length();i++){
			t=s[i];
			//cout<<state;
			//ini st=0
			if(t=='l'&&state==0){
				state=1;
				r=r+"level "+t;
			}
			else if((int)t>=48&&(int)t<=57 && state==1){
				r=r+t;
			}
			else if((t==' '||t=='\n')&& state==1){
				r=r+"\n";
				state=2;
			}
			//id st=2
			else if((int)t>=48&&(int)t<=57 && state==2){
				state=3;
				r=r+"cid "+t;
			}
			else if((int)t>=65 && (int)t<=90&& state==2){
				state=4;
				r=r+"FirstName "+t;
			}
			//cid st=3
			else if((int)t>=48&&(int)t<=57 && state==3){
				r=r+t;
			}
			else if((t==' '||t=='\n')&& state==3){
				r=r+"\n";
				state=6;
			}
			//FirstName st=4
			else if((int)t>=97 && (int)t<=122 && state==4){
				r=r+t;
			}
			else if((t==' '||t=='\n')&& state==4){
				r=r+"\n";
				r=r+"LastName ";
				state=5;
			}
			//LastName st=5
			else if(((int)t==97||((int)t>98&&(int)t<=122)) && state==5){
				r=r+t;
				if(Dcl==false){
					cout<<r;
					over=true;
					break;
				}
			}
			else if((t==' '||t=='\n')&& state==5){
				r=r+"\n";
				state=6;
			}
			//battle st=6
			else if(t=='b'&&state==6&&Dcl==true){
				r=r+"battle b\n";
				Dcl=false;
				state=2;
			}
			else if(state==6&&Dcl==false){
				cout<<r;
				over=true;
				break;
			}
			else if((t!=' '&&t!='\n')){
				cout<<"invalid input";
				over=true;
				break;
			}
		}

	}
	system("pause");
	return 0;
}