#include <iostream>
#include <string>
using namespace std;

int main(){
	string store, line;
	int input_counter = 1,c,buff;
	getline(cin, store);
	string output[7];
	output[0] = "strdcl s";
	output[1] = output[6] = "id ";
	output[2] = output[4] = "quote ";
	output[3] = "string ";
	output[5] = "print p";
	output[2] += '"';
	output[4] += '"';

	while(getline(cin, line)){
		store = store + '@' + line;
		input_counter++;
	}

	if(input_counter != 2){
		cout <<"valid input";
	}
	else{
		buff = 0;
		c = 0;
		if(store[c] == 's'){
			c++;
			while(c < store.size()){
				if(store[c] == ' ' && buff != 2){
					c++;
				}
				else if(store[c] == '@' && buff != 2){
					c++;
				}
				else if(buff == 0){
					if( islower(store[c])){
						if(store[c] == 'p' || store[c] == 's'){
							cout <<"valid input1";
							break;
						}
						else{	
							output[1] += store[c];
							c++;
							buff = 1;
						}
					}
					else{
						cout <<"valid input2";
							break;
					}
				}
				else if(buff == 1){
					if(store[c] == '"'){
						c++;
						buff = 2;
					}
					else{
						cout <<"valid input3";
						break;
					}
				}
				else if(buff == 2){
					if(isalpha(store[c]) || isdigit(store[c])){
						output[3] += store[c];
						c++;
					}
					else if(store[c] == '"'){
						c++;
						buff = 3;
					}
					else{
						cout <<"valid input4";
						break;
					}
				}
				else if(buff == 3){
					if(store[c] == 'p'){
						c++;
						buff = 4;
					}
					else{
						cout <<"valid input5";
						break;
					}
				}
				else if(buff == 4){
					if(c == (store.size() - 1)  && islower(store[c])){
						if(store[c] == 'p' ||store[c] == 's'){
							cout <<"valid input6";
							break;
						}
						else{	
							output[6] += store[c];
							buff = 5;
							break;
						}
					}
					else{
						cout <<"valid input7";
						break;
					}
				}
			}
			if(buff == 5){
				for(int i = 0; i<7; i++){
					cout << output[i] <<endl;
				}
			}
		}
		else{
			cout <<"valid input8";
		}
	}
	return 0;
}