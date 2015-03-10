#include <iostream>
#include <cstdlib>
#include <string>
#include <string.h>
using namespace std;
struct token {
	string ter;
	string var;
};
int main() {
	string input;
	bool get = true;
	token last_token;
	last_token.ter = "NULL";
	token tokens[4];
	int token_count = 0;
	const char* input_char;
	bool lp =false;
	bool end = false;
	while( true ) {
		if (end ) {
			break;
		}
		cin>>input;
		input_char = input.c_str();
		
		while( input != "" ) {
			/*cout<<"debug: "<<input<<endl;
			system("pause");*/
			int char_count = 1;
			if( input_char[0] =='(' ) {
				lp = true;
				if( last_token.ter == "id" ) {
					get = false;
					tokens[token_count].ter ="lparenthesis";
					tokens[token_count].var = '(';
					token_count++;
					if( input.length() > 1 ) {
						string temp(input.begin() +1, input.end());
						input.assign(temp);
						input_char = input.c_str();
					}
					else {
						break;
					}
				}
				else {
					cout<<"invalid input"<<endl;
					return 0;
				}
			}
			else if( input_char[0] ==')' ) {
				if( (last_token.ter == "id" || last_token.ter == "inum") && input.length() == 1 ) {
					tokens[token_count].ter ="rparenthesis";
					tokens[token_count].var = ')';
					token_count++;
					input="";
					end = true;
				}
				else {
					cout<<"invalid input"<<endl;
					return 0;
				}
			}
			else if ( input_char[0] >='0' && input_char[0] <='9' ) {
				while( input_char[char_count] >='0' && input_char[char_count] <='9' ) {
					char_count++;
				}
				if ( char_count == strlen(input_char)-1 && lp && input_char[input.length()-1] == ')' ) {
					string temp(input.begin(), input.end() -1 );
					tokens[token_count].ter ="inum";
					tokens[token_count].var = temp;
					token_count++;
					last_token.ter ="inum";
					last_token.var = input;
					string temp2(input.end()-1, input.end() );
					input.assign(temp2);
					input_char = input.c_str();
				}
				else if ( char_count == strlen(input_char) ) {
					tokens[token_count].ter ="inum";
					tokens[token_count].var = input;
					token_count++;
					last_token.ter ="inum";
					last_token.var = input;
					break;
				}
				else {
					cout<<"invalid input"<<endl;
					return 0;
				}
			}
			else if ( ( input_char[0] >='a' && input_char[0] <='z') || ( input_char[0] >='A' && input_char[0] <='Z') || ( input_char[0] =='_') ) {
				while( ( input_char[char_count] >='a' && input_char[char_count] <='z') || ( input_char[char_count] >='A' && input_char[char_count] <='Z') || ( input_char[char_count] =='_') ) {
					char_count++;
				}
				if(char_count == input.length() ) {
					if ( last_token.ter == "NULL" ) {
						tokens[token_count].ter ="id";
						tokens[token_count].var = input;
						token_count++;
						last_token.ter ="id";
						last_token.var = input;
						input="";
						break;
					}
				}
				else if( char_count == input.length()-1 && lp && input_char[input.length()-1] == ')' ) {
					if ( lp && last_token.ter == "lparenthesis" ) {
						string temp(input.begin(), input.end() -1 );
						input.assign(temp);
						input_char = input.c_str();
						tokens[token_count].ter ="id";
						tokens[token_count].var = input;
						token_count++;
						last_token.ter ="id";
						last_token.var = input;
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
			else {
				cout<<"invalid input"<<endl;
				system("pause");
				return 0;
			}
			if( token_count >= 4 ) {
				break;
			}
		}
	}
	for( int i = 0; i< 4;i++) {
		cout<<tokens[i].ter<<" "<<tokens[i].var<<endl;
	}
	system("pause");
	return 0;
}