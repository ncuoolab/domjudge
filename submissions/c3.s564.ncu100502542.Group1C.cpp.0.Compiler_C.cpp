#include <iostream>
#include <string>
using namespace std;
struct {
	string id;
	string value;
}typedef token;
void checkGrammar(string);
bool checkId(string);
bool checkFunc(string);
bool checkinum(string);
bool printVaild();
void printResult(string result[]);
token t[20];
bool printVaild(){
	cout<<"invalid input"<<endl;
	return true;
}
void checkGrammar(string input){
	string tId;
	string func;
	size_t foundL =input.find("(");
	size_t foundR =input.find(")");
	if(foundL!=string::npos&&foundR!=string::npos&&foundR==input.size()-1){
		tId=input.substr(0,foundL);
		func=input.substr(foundL,(foundR-foundL)+1);
		if(!checkId(tId))
			printVaild();
		else{
			t[0].id="id";
			t[0].value=tId;
		}
		t[1].id="lparenthesis";
		t[1].value="(";
		t[3].id="rparenthesis";
		t[3].value=")";
		if(!checkFunc(func)){
			if(printVaild())
				return;
		}
	}
	else{
		if(printVaild())
				return;
	}
	for(int i=0;i<4;i++){
		cout<<t[i].id<<" "<<t[i].value<<endl; 
	}

}
bool checkId(string id){
	int i=0;
	while(i<id.size()){
		if(!((id[i]>=65&&id[i]<=90)||id[i]==95||(id[i]>=97&&id[i]<=122)))
			return false;
		i++;
	}
	return true;


}
bool checkinum(string inum){
	int i=0;
	while(i<inum.size()){
		if(!(inum[i]>=48&&inum[i]<=57))
			return false;
		i++;
	}
	return true;
}
bool checkFunc(string func){
	string sub=func.substr(1,func.size()-2);
	
	if(checkinum(sub)){
		t[2].id="inum";
		t[2].value=sub;
	}
	else if(checkId(sub)){
		t[2].id="id";
		t[2].value=sub;
	}
	else if(sub==""){
		t[2].id="";
		t[2].value="";
	}else 
		return false;
	return true;
}
int main(){
	string tinput;
	string rInput;
	while(cin>>tinput)
		rInput=rInput.append(tinput);
	checkGrammar(rInput);
	return 0;

}