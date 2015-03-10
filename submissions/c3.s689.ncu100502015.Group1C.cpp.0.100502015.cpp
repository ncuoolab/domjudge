#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;
void scanner(string input);
int main()
{
	string word; 
	getline(cin,word);
	
	scanner(word);
	system("PAUSE");
	return 0;
}
void scanner(string input){
	int i=0;
	int store=0;
	string output ="";
	bool correct =true;
	while(i<=input.size()-1){
		if(input[i] >= 'a' && input[i] <='z' || input[i] >= 'A' && input[i] <='Z' || input[i]==' '){			
			i++;
		}		
		else if(input[i] == '(' ){
			output+="id ";
			for(int j=0;j<i;j++)
			{
				output += input[j];
			}
			output+="\n";	
			output+="lparenthesis (\n";
			i++;
			if(input[i]==' '){
				i++;
			}
				
				if(input[i] >= 'a' && input[i] <='z' || input[i] >= 'A' && input[i] <='Z'){
					output+="id ";			
					while(i<=input.size()-1){
						//cout<<input[i]<<endl;
						if(input[i] >= 'a' && input[i] <='z' || input[i] >= 'A' && input[i] <='Z'){
						
							output+=input[i];
						}
						else if(input[i]==')'){						
							output+="\n";
							output+="rparenthesis )";
						}					
						else {						
							correct=false;
						}
						i++;
					}				
				}
				else if(input[i] >= '0' && input[i] <='9' ){
					output+="inum ";			
					while(i<=input.size()-1){
						if(input[i] >= '0' && input[i] <='9' ){
							output+=input[i];
						}
						else if(input[i]==')'){
							output+="\n";
							output+="rparenthesis )";
						}					
						else {
							correct=false;
						}
						i++;
					}
				}
			}
		
		else{
			correct = false;
			break;
		}
	}
	if(correct==false){
		output="invalid input";
	}
	cout<<output;
}
/*
void scanner(string input){
	string output="";
	bool correct =true;
	for(int j=0;j<input.size();j++)
	{		
		if((input[j] >= 'a' && input[j] <='z') || (input[j] >= 'A' && input[j] <='Z')){		
		}
		else{
			correct = false;
			//cout<<"1"<<endl;
			output = "invalid input";
		}			
	}
	if(correct){
		bool correct1 =true;
		string value;
		output+="id ";
		output+=input;
		output+="\n";
		cin >> value;
		if(value[0] == '(' && value[value.size()-1] ==')' ){			
		}
		else{
			correct1 = false;
			//cout<<"2"<<endl;
			output = "invalid input";
		}
		if(correct1){
			bool correct2=true;
			for(int k=1;k<value.size()-1;k++)
			{		
				if(value[k] >= '0' && value[k] <='9' || (input[k] >= 'a' && input[k] <='z') || (input[k] >= 'A' && input[k] <='Z')){
				}
				else{
					correct2 = false;
					//cout<<value[k]<<endl;
					//cout<<"3"<<endl;
					output = "invalud input";
				}			
			}
			if(correct2){
				output+="lparenthesis (\n";
				if((value[1] >= 'a' && value[1] <='z') || (value[1] >= 'A' && value[1] <='Z'))
				{
					output+="id ";
				}
				else{				
					output+="inum ";
				}
				for(int i=1;i<=value.size()-2;i++){
					output += value[i];
				}
				output+="\n";
				output+="rparenthesis )";
			}
		}
	}		
	cout<<output;
}*/

	