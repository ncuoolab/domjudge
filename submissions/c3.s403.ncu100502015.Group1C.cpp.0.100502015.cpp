#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;
void scanner(string input);
int main()
{
	string word; 
	cin>>word;
	scanner(word);
	system("PAUSE");
	return 0;
}
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
				if(value[k] >= '0' && value[k] <='9' ){
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
				output+="inum ";			
				for(int i=1;i<=value.size()-2;i++){
					output += value[i];
				}
				output+="\n";
				output+="rparenthesis )";
			}
		}
	}		
	cout<<output;
}

	