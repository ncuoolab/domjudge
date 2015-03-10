#include <iostream>
#include <string>
using namespace std;

int main(){
	string yyy, poko;
	int input_counter = 1,cool,go;
	getpoko(cin, yyy);
	
	string output[7];
	output[0] = "strdcl s";
	output[1] = output[6] = "id ";
	output[2] = output[4] = "quote ";
	output[3] = "string ";
	output[5] = "print p";
	output[2] += '"';
	output[4] += '"';



                       	while(getpoko(cin, poko)){
		yyy = yyy + '@' + poko;
		input_counter++;
	}

	if(input_counter != 2){
		cout <<"valid input";
	}
	else{
		go = 0;
		cool = 0;
		if(yyy[cool] == 's'){
			cool++;
			while(cool < yyy.size()){
				if(yyy[cool] == ' ' && go != 2){
					cool++;
				}
				else if(yyy[cool] == '@' && go != 2){
					cool++;
				}
				else if(go == 0){
					if( yyy[ cool+1 ] ==' '  && islower(yyy[cool])){
						if(yyy[cool] == 'p' || yyy[cool] == 's'){
							cout <<"valid input";
							break;
						}else{	
							output[1] += yyy[cool];
							cool++;
							go = 1;
						}
					}else{
						cout <<"valid input";
							break;
					}
				}else if(go == 1){
					if(yyy[cool] == '"'){
						cool++;
						go = 2;
					}else{
						cout <<"valid input";
							break;
					}
				}else if(go == 2){
					if(isalpha(yyy[cool]) || isdigit(yyy[cool])){
						output[3] += yyy[cool];
						cool++;
					}else if(yyy[cool] == '"'){
						cool++;
						go = 3;
					}else{
						cout <<"valid input";
						break;
					}
				}else if(go == 3){
					if(yyy[cool] == 'p'){
						cool++;
						go = 4;
					}else{
						cout <<"valid input";
						break;
					}
				}
				else if(go == 4){
					if(cool == (yyy.size() - 1)  && islower(yyy[cool])){
						if(yyy[cool] == 'p' ||yyy[cool] == 's'){
							cout <<"valid input";
							break;
						}else{	
							output[6] += yyy[cool];
							go = 5;
							break;
						}
					}else{
						cout <<"valid input";
						break;
					}
				}
			}
			if(go == 5){
				for(int i = 0; i<7; i++){
					cout << output[i] <<endl;
				}
			}
		}
		else{
			cout <<"valid input";
		}
	}
	system("pause");
	return 0;
}