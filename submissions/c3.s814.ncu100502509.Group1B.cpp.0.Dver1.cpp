#include <iostream>
#include <cstring>
using namespace std;

struct token{
	string type;
	string val;
};

token* scanner(string);
string scanLevel(char**);
string scanFirstName(char**);
string scanLastName(char**);
string scanDigit(char**);
string scanId(char**);
void proc(token*,int);
void stmt(token*,int);
void val(token*,int);

int main(){
	string input;	
	getline(cin,input);
	token* tokens = scanner(input);
	//cout << tokens[4].type << endl;
	proc(tokens,0);
	return 0;
}

token* scanner(string str){
	char *str_pointer;
	str_pointer = &str[0];
	static token tokens[30];
	int index = 0;
	
	while(*str_pointer != '\0'){
		if(*str_pointer != '\n'){
			if(*str_pointer<=57 && *str_pointer>=48 ){
				token t;
				t.val = scanDigit(&str_pointer);
				t.type = "cid";
				tokens[index] = t;
				//cout<< tokens[index].type << " " << tokens[index].val << endl;
				index++;
				//str_pointer++; // *c already move next (scanDigit) 
				continue;
			}else if(*str_pointer == 108 ){
				token t;
				t.val = *str_pointer;
				str_pointer++;
				t.val = t.val + scanLevel(&str_pointer);
				t.type = "level";
				tokens[index] = t;
				//cout<< tokens[index].type << " " << tokens[index].val << endl;
				index++;
				//str_pointer++; // *c already move next (scanDigit) 
				continue;
			}else if(*str_pointer >= 65 && *str_pointer <= 90 ){
				token t;
				t.val = *str_pointer;
				str_pointer++;
				t.val = t.val + scanFirstName(&str_pointer);
				t.type = "FirstName";
				tokens[index] = t;
				//cout<< tokens[index].type << " " << tokens[index].val << endl;
				index++;
				//str_pointer++; // *c already move next (scanDigit) 
				continue;
			}else if(*str_pointer == 97  || (*str_pointer>=99 && *str_pointer <=122) ){
				token t;
				t.val = *str_pointer;
				str_pointer++;
				t.val = t.val + scanLastName(&str_pointer);
				t.type = "LastName";
				tokens[index] = t;
				//cout<< tokens[index].type << " " << tokens[index].val << endl;
				index++;
				//str_pointer++; // *c already move next (scanDigit) 
				continue;
			}else if(*str_pointer == 98){
				token t;
				t.val = *str_pointer;
				t.type = "battle";
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

string scanId(char **c){
	string val;
	while( (**c <=122 && **c >=97) || (**c >= 65 && **c <=90) || **c == 95 ){
		val += **c;
		(*c)++;
	}
	return val;
}

string scanLevel(char **c){
	string val = "";
	while(  **c <=57 && **c >=48  ){
		val += **c;
		(*c)++;
	}
	return val;
}

string scanFirstName(char **c){
	string val;
	while( **c <=122 && **c >=97 ){
		val += **c;
		(*c)++;
	}
	return val;
}

string scanLastName(char **c){
	string val = "";
	while( **c == 97  || ( **c<=122 && **c >=99) ){
		val += **c;
		(*c)++;
	}
	return val;
}

void proc(token* tokens, int index){
	if( tokens[index].type == "level" ){
		stmt(tokens,index);	
	}else{
		cout << "invalid input";
	}
}

void stmt(token* tokens, int index){
	int temp = index;
	
	if( tokens[index].type == "level" ){
		index++;
		if( tokens[index].type == "cid" ){
			index++;
			if(tokens[index].type == "battle"){
				index++;
				if( tokens[index].type == "cid" ){
					cout<< tokens[temp].type << " " << tokens[temp].val << endl;
					temp++;
					cout<< tokens[temp].type << " " << tokens[temp].val << endl;
					temp++;
					cout<< tokens[temp].type << " " << tokens[temp].val << endl;
					temp++;
					cout<< tokens[temp].type << " " << tokens[temp].val;				
				}else if(tokens[index].type == "FirstName" ){
					index++;
					if( tokens[index].type == "LastName" ){
						cout<< tokens[temp].type << " " << tokens[temp].val << endl;
						temp++;
						cout<< tokens[temp].type << " " << tokens[temp].val << endl;
						temp++;
						cout<< tokens[temp].type << " " << tokens[temp].val << endl;
						temp++;
						cout<< tokens[temp].type << " " << tokens[temp].val << endl;
						temp++;
						cout<< tokens[temp].type << " " << tokens[temp].val;
					}else{
						cout << "invalid input";
					}
				}else{
					cout << "invalid input";
				}
			}else{
				cout << "invalid input";
			}
		}else if(tokens[index].type == "FirstName" ){
			index++;
			if( tokens[index].type == "LastName" ){
				index++;
				if(tokens[index].type == "battle"){
					index++;
					if( tokens[index].type == "cid" ){
						cout<< tokens[temp].type << " " << tokens[temp].val << endl;
						temp++;
						cout<< tokens[temp].type << " " << tokens[temp].val << endl;
						temp++;
						cout<< tokens[temp].type << " " << tokens[temp].val << endl;
						temp++;
						cout<< tokens[temp].type << " " << tokens[temp].val << endl;
						temp++;
						cout<< tokens[temp].type << " " << tokens[temp].val;
					}else if(tokens[index].type == "FirstName" ){
						index++;
						if( tokens[index].type == "LastName" ){
							cout<< tokens[temp].type << " " << tokens[temp].val << endl;
							temp++;
							cout<< tokens[temp].type << " " << tokens[temp].val << endl;
							temp++;
							cout<< tokens[temp].type << " " << tokens[temp].val << endl;
							temp++;
							cout<< tokens[temp].type << " " << tokens[temp].val << endl;
							temp++;
							cout<< tokens[temp].type << " " << tokens[temp].val << endl;
							temp++;
							cout<< tokens[temp].type << " " << tokens[temp].val;
						}else{
							cout << "invalid input";
						}
					}else{
						cout << "invalid input";
					}
				}else{
					cout << "invalid input";
				}
			}else {
				cout << "invalid input";
			}
		}else {
			cout << "invalid input";
		}
	}else {
		cout<< "invalid input";
	}
}



