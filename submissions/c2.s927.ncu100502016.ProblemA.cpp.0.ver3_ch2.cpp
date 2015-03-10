#include <iostream>
#include <cstring>
using namespace std;

struct token{
	string type;
	string val;
};

token* scanner(string);
string scanDigit(char**);
void proc(token*,int);
void stmt(token*,int);
void val(token*,int);

int main(){
	string input;	
	getline(cin,input);
	token* tokens = scanner(input);
	//cout << tokens[2].type << endl;
	proc(tokens,0);
	return 0;
}

token* scanner(string str){
	char *str_pointer;
	str_pointer = &str[0];
	static token tokens[100];
	int index = 0;
	
	while(*str_pointer != '\0'){
		if(*str_pointer != '\n'){
			if(*str_pointer<=57 && *str_pointer>=48 ){
				token t;
				t.val = scanDigit(&str_pointer);
				t.type = "inum";
				tokens[index] = t;
				//cout<< tokens[index].type << " " << tokens[index].val << endl;
				index++;
				//str_pointer++; // *c already move next (scanDigit) 
				continue;
			}else if(*str_pointer <=122 && *str_pointer>=97){
				token t;
				t.val = *str_pointer;
				t.type = "id";
				tokens[index] = t;
				//cout<< tokens[index].type << " " << tokens[index].val << endl;
				index++;
				str_pointer++;
				continue;
			}else if(*str_pointer ==61 ){
				token t;
				t.val = *str_pointer;
				t.type = "assign";
				tokens[index] = t;
				//cout<< tokens[index].type << " " << tokens[index].val << endl;
				index++;
				str_pointer++;
				continue;
			}else{
				str_pointer++;
			}			
		}	
	}
	return tokens;
}

string scanDigit(char **c){
	string val;
	while( **c <=57 && **c >=48 ){
		val += **c;
		(*c)++;
	}
	return val;
}

void proc(token* tokens, int index){
	if( tokens[index].type == "id" ){
		stmt(tokens,index);
	}else{
		cout << "valid input";
	}
}

void stmt(token* tokens, int index){
	int temp = index;
	
	if( tokens[index].type == "id" ){
		index++;
		if( tokens[index].type == "assign" ){
			index++;
			if( tokens[index].type == "id" || tokens[index].type == "inum"){
				cout<< tokens[temp].type << " " << tokens[temp].val << endl;
				temp++;
				cout<< tokens[temp].type << " " << tokens[temp].val << endl;
				temp++;
				cout<< tokens[temp].type << " " << tokens[temp].val;
			}else {
				cout << "valid input";
		}
		}else {
			cout << "valid input";
		}
	}else {
		cout << "valid input";
	}
}



