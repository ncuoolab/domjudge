#include <string>
#include<iostream>
using namespace std;
void checkGrammar(string input);
void vaildGrammar();
void printResult();
int state=0;
string result[7];
/**
print vaild result and exit;
**/
void vaildGrammar(){
	cout<<"vaild input"<<endl;
	exit(1);
}
/**
print token and the corresponding result[];

**/
void printResult(){
	for(int i=0;i<7;i++){
		switch (i)
		{
		case 0:
			cout<<"strdcl";
			break;
		case 1:
			cout<<"id";
			break;
		case 2:
			cout<<"quote";
			break;
		case 3:
			cout<<"string";
			break;
		case 4:
			cout<<"quote";
			break;
		case 5:
			cout<<"print";
			break;
		case 6:
			cout<<"id";
			break;
		default:
			break;
		}
		cout<<" "<<result[i]<<endl;
	}
}
/**
check the Grammar and set result;
**/
void checkGrammar(string input){
	unsigned int count=0;
	int sCount=0;
	bool checkS=false;
	char temp[100]={" "};
	while(count<input.size()){
			char c=input[count];
			switch(state){		
				case 0:
					if(c=='s'){
						result[state]=c;
						state++;
					}
					else
						vaildGrammar();
					break;
				case 1:
					if((97<=c&&c<=111) || c==71 || c==72 || (116<=c&&c<=122)){
						result[state]=c;
						state++;
					}
					else
						vaildGrammar();
					break;
				case 2:
					if(c=='\"'){
						result[state]=c;
						state++;
					}
					else
						vaildGrammar();
					break;
				case 3:
					if((65<=c&&c<=90)||(97<=c&&c<=122)||(48<=c&&c<=57)){
						temp[sCount]=c;
						sCount++;
						checkS=true;
					}
					else if(checkS&&c=='\"'){
						result[state]=temp;
						state++;
					}
					else
						vaildGrammar();
					break;
				case 4:
						result[state]='\"';
						state++;
						count--;
					break;
				case 5:
					if(c=='p'){
							result[state]=c;
							state++;
						}
					else
						vaildGrammar();
					break;
				case 6:
						if((97<=c&&c<=111) || c==71 || c==72 || (116<=c&&c<=122)){
							result[state]=c;
							state++;
							printResult();
						}
					else
						vaildGrammar();
					break;
				default:
					vaildGrammar();
					break;

			}
			count++;
	}
}	
int main(){
	string input;
	string res;
	//it will cut whitespace and append to input String;
	while(cin>>input){
		res.append(input);
	}
	checkGrammar(res);
	return 0;
}
