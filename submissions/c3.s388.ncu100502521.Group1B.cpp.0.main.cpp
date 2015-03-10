#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

struct token {
	string terminal;
	string var;
};
int main() {
	string input;
	token tokens[6];
	token last_token;
	last_token.terminal = "NULL";
	int token_count = 0;
	bool stmt = false;
	bool end = false;
	while( true ) {
		cin>>input;
		//cout<<"debug: "<<token_count<<endl;
		//cout<<input<<endl;
		const char* input_char = input.c_str();
		//cout<<input_char[0]<<endl;
		int char_count = 1;
		if ( end && input.length() > 0 ) {
			cout<<"invalid input"<<endl;
			return 0;
		}
		if ( input_char[0] == 'l' ) {
			//cout<<"level"<<endl;
			while( input_char[char_count] >= '0' && input_char[char_count] <= '9' ) {
				char_count++;
			}
			if ( char_count == input.length() ) {
				//cout<<"Level "<<input<<endl;
				if( last_token.terminal == "NULL" ) {
					last_token.terminal = "level";
					last_token.var = input;
					tokens[token_count].terminal = "level";
					tokens[token_count].var = input;
					token_count++;
				}
				else {
					cout<<"invalid input"<<endl;
					return 0;
				}
			}
			else {
				cout<<"invalid input"<<endl;
				return 0;
			}
		}
		else if ( input_char[0] == 'b' ) {
			if ( input.length() == 1 ) {
				//cout<<"battle "<<input<<endl;
				if( last_token.terminal == "cid" || last_token.terminal == "LastName" ) {
					last_token.terminal = "battle";
					last_token.var = input;
					tokens[token_count].terminal = "battle";
					tokens[token_count].var = input;
					token_count++;
					stmt = true;
				}
				else {
					cout<<"invalid input"<<endl;
					return 0;
				}
			}
			else {
				cout<<"invalid input"<<endl;
				return 0;
			}
		}
		else if ( input_char[0] >= 'A' && input_char[0] <= 'Z' ) {
			//cout<<"First name"<<endl;
			while( input_char[char_count] >= 'a' && input_char[char_count] <= 'z' ) {
				char_count++;
			}
			if ( char_count == input.length() ) {
				//cout<<"FirstName "<<input<<endl;
				if( last_token.terminal == "level" || last_token.terminal == "battle" ) {
					last_token.terminal = "FirstName";
					last_token.var = input;
					tokens[token_count].terminal = "FirstName";
					tokens[token_count].var = input;
					token_count++;
				}
				else {
					cout<<"invalid input"<<endl;
					return 0;
				}
			}
			else {
				cout<<"invalid input"<<endl;
				return 0;
			}
		}
		else if ( input_char[0] >= 'a' && input_char[0] <= 'z' ) {
			//cout<<"last name"<<endl;
			while( input_char[char_count] >= 'a' && input_char[char_count] <= 'z' && input_char[char_count] != 'b' ) {
				char_count++;
			}
			if ( char_count == input.length() ) {
				//cout<<"LastName "<<input<<endl;
				if( last_token.terminal == "FirstName" ) {
					last_token.terminal = "LastName";
					last_token.var = input;
					tokens[token_count].terminal = "LastName";
					tokens[token_count].var = input;
					token_count++;
					if ( stmt ) {
						end = true;
					}
				}
				else {
					cout<<"invalid input"<<endl;
					return 0;
				}
			}
			else {
				cout<<"invalid input"<<endl;
				return 0;
			}
		}
		else if ( input_char[0] >= '0' && input_char[0] <= '9' ) {
			//cout<<"cid"<<endl;
			while( input_char[char_count] >= '0' && input_char[char_count] <= '9' ) {
				char_count++;
			}
			if ( char_count == input.length() ) {
				//cout<<"cid "<<input<<endl;
				if( last_token.terminal == "level" || last_token.terminal == "battle" ) {
					last_token.terminal = "FirstName";
					last_token.var = input;
					tokens[token_count].terminal = "FirstName";
					tokens[token_count].var = input;
					token_count++;
					if ( stmt ) {
						end = true;
					}
				}
				else {
					cout<<"invalid input"<<endl;
					return 0;
				}
			}
			else {
				cout<<"invalid input"<<endl;
				return 0;
			}
		}
		if ( token_count >= 6 ) {
			end = true;
		}
	}
	for ( int i = 0 ; i < token_count ; i++ ) {
		cout<<tokens[i].terminal<<" "<<tokens[i].var<<endl;
	}
	system("pause");
	return 0;
}