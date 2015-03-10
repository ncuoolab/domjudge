#include <iostream>
#include <cstdlib>
#include<string>
using namespace std;

struct token {
	string ter;
	string var;
};
string scan(char input) {
	if ( input >= 'a' && input <= 'z' ) {
		return "id";
	}
	else if ( input == '=' ) {
		return "assign";
	}
	else if ( input >= '0' && input <= '9' ) {
		return "inum";
	}
	else if ( input == ' ' ) {
		return "space";
	}
	else {
		return "vaild";
	}
}
int main() {
	string input;
	getline(cin, input);
	const char* input_char = input.c_str();
	//cout<<input_char<<endl;
	token last_token;
	last_token.ter = "null";
	last_token.var = "";
	bool assinged = false;
	token tokens[3];
	int token_count = 0;
	for(int char_index = 0 ; char_index< input.length() ; char_index++ ) {
		//cout<<input_char[char_index]<<endl;
		string type = scan(input_char[char_index]);
		if ( last_token.ter == "null" ) {
			if ( type == "id" ) {
				last_token.ter = "id";
				last_token.var = input_char[char_index];
			}
			else if ( type == "assign" ) {
				cout<<"vaild input"<<endl;
				system("pause");
				return 0;
			}
			else if ( type == "inum" ) {
				cout<<"vaild input"<<endl;
				system("pause");
				return 0;
			}
			else if ( type == "space" ) {
				continue;
			}
			else {
				cout<<"vaild input"<<endl;
				system("pause");
				return 0;
			}
		}
		else if ( last_token.ter == "id" ) {
			if ( type == "id" ) {
				cout<<"vaild input"<<endl;
				system("pause");
				return 0;
			}
			else if ( type == "assign" ) {
				if( !assinged ) {
					tokens[token_count] = last_token;
					token_count++;
					last_token.ter = "assign";
					last_token.var = "=";
					assinged = true;
					tokens[token_count] = last_token;
					token_count++;
				}
				else {
					cout<<"vaild input"<<endl;
					system("pause");
					return 0;
				}
			}
			else if ( type == "inum" ) {
				cout<<"vaild input"<<endl;
				system("pause");
				return 0;
			}
			else if ( type == "space" ) {
				continue;
			}
			else {
				cout<<"vaild input"<<endl;
				system("pause");
				return 0;
			}
		}
		else if ( last_token.ter == "assign" ) {
			if ( type == "id" ) {
				if ( char_index < input.length() - 1 ) {
					for ( int temp = char_index+1 ; temp < input.length() ; temp++ ) {
						if( input_char[temp] != ' ' ) {
							cout<<"vaild input"<<endl;
							system("pause");
							return 0;
						}
					}
				}
				else {
					last_token.ter = "id";
					last_token.var = input_char[char_index];
					tokens[token_count] = last_token;
					token_count++;
					break;
				}

			}
			else if ( type == "assign" ) {
				cout<<"vaild input"<<endl;
				system("pause");
				return 0;
			}
			else if ( type == "inum" ) {
				last_token.ter = "inum";
				last_token.var = "";
				last_token.var = last_token.var + input_char[char_index];
				tokens[token_count].ter = "inum";
				tokens[token_count].var = tokens[token_count].var + input_char[char_index];
			}
			else if ( type == "space" ) {
				/*if ( last_token.var != "") {
					cout<<"vaild input10"<<endl;
					system("pause");
					return 0;
				}
				else {*/
					continue;
				//}
			}
			else {
				cout<<"vaild input"<<endl;
				system("pause");
				return 0;
			}
		}
		else if ( last_token.ter == "inum" ) {
			if ( type == "inum" ) {
				last_token.var = last_token.var + input_char[char_index];
				tokens[token_count].var = tokens[token_count].var + input_char[char_index];
				token_count = 2;
			}
			else {
				cout<<"vaild input"<<endl;
				system("pause");
				return 0;
			}
		}
		else {
			cout<<"vaild input"<<endl;
			system("pause");
			return 0;
		}
	}
	if ( token_count != 3 && last_token.ter != "inum" ) {
		cout<<"vaild input"<<endl;
		system("pause");
		return 0;
	}
	for ( int i = 0;i < 3 ;i++ ) {
		cout<< tokens[i].ter <<" "<<tokens[i].var<<endl;
	}
	system("pause");
	return 0;
}