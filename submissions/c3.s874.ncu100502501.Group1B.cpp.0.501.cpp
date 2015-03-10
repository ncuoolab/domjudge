#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

string test_1[10];
int tokens[6];

void scanner(string);
bool digit(char);
bool cid(string);
bool lev(string);
bool trytry(int);
int term(char);
int Nam(string);

bool digit(char input){
	if(input>=48&&input<=57)
		return true;
	return false;
}

bool lev(string input){
	if(input[0]==108){
		if(input.length()>1){
			for(int j=1;j<(signed)input.length();j++){
				if(!digit(input[j]))
					return false;
			}
			return true;
		}
		else
			return false;
	}
	else
		return false;
}

int term(char input){
	if(input>=97&&input<=122)
		return 0;
	else if(input>=65&&input<=90)
		return 1;
	else
		return 3;
	return 3;
}
int Nam(string input){
	if(term(input[0])==1){
		if(input.length()>1){
			for(int j=1;j<(signed)input.length();j++){
				if(term(input[j])==1){
					return 3;
				}
				else if(digit(input[j])){
					return 3;
				}
			}
			return 1;
		}
		return 1;
	}
	else if (term(input[0])==0 &&input[0]!=98){
		if(input.length()>1){
			for(int j=1;j<(signed)input.length();j++){
				if(term(input[j])==1){
					return 3;
				}
				else if(digit(input[j])){
					return 3;
				}
				else if(input[j]==98)
					return 3;
			}
			return 2;
		}
		return 2;
	}
	return 3;
}

bool cid(string input){
	for(int i=0;i<(signed)input.length();i++){
		if(!digit(input[i]))
			return false;
	}
	return true;
}

bool trytry(int count){
	if(tokens[0]!=1)
		return false;
	for(int i=1;i<count;i++){
		if(tokens[i]==1)
			return false;
	}
	if(tokens[1]==2 && tokens[2]==3 ){
		if(tokens[3]!=5)
			return false;
		if(tokens[count]==4)
			return true;
		else if(tokens[count-1]==2 || tokens[count]==3)
			return true;
		else
			return false;
	}
	if(tokens[1]==4){
		if(tokens[2]!=5)
			return false;
		if(tokens[count]==4)
			return true;
		else if(tokens[count-1]==2 || tokens[count]==3)
			return true;
		else
			return false;
	}
	return true;
}

int main(){
	string input;
	int count=0;
	bool check=false;
	while(cin>>input){
		if(!lev(input) && count==0){
			cout<<"invalid input";
			return 0;
		}
		else if(count==1){
			if(input=="b" || Nam(input)==2 || lev(input)){
				cout<<"invalid input";
				return 0;
			}
		}
		scanner(input);
		if(tokens[count-1]==2){
			if(tokens[count]!=3){
				cout<<"invalid input";
				return 0;
			}
		}

		if(input=="b"){
			check = true;
		}
		if(check==true){
			if(tokens[count]==4)
				break;
			else if(tokens[count-1]==2 && tokens[count]==3)
				break;
		}
		count++;
	}

	if(trytry(count)){
		for(int i=0;i<count+1;i++){
			cout<<test_1[i]<<endl;
		}
	}
	else
		cout<<"invalid input"<<endl;

	system("pause");
	return 0;
}

void scanner(string input){
	static int count=0;
	if(input=="B"){
		tokens[count]=5;
		test_1[count++]="battle "+input;
	}
	else if(lev(input)){
		tokens[count]=1;
		test_1[count++]="level "+input;
	}
	else if(Nam(input)==1){
		tokens[count]=2;
		test_1[count++]="FirstName "+input;
	}
	else if(Nam(input)==2){
		tokens[count]=3;
		test_1[count++]="LastName "+input;
	}
	else if(cid(input)){
		tokens[count]=4;
		test_1[count++]="cid "+input;
	}
	else{
		cout<<"invalid input"<<endl;
	}
}

