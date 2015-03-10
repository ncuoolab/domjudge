#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;
string inputORI, input;


int main()
{
    int count_token=0;
    int len_token[5]={0,0,0,0,0};
    bool check_strdcl=false;
    bool check_id=false;
    bool check_l_quote=false;
    bool check_r_quote=false;
    bool check_string=false;
    bool check_print=false;
    string id;
    string content;
    getline(cin,inputORI);
    for(int i=0;i<inputORI.length();i++)
	{
		while(inputORI[i]-' '==0){
			i++;
        }
		input=input+inputORI[i];
	}
	
	for(int i=0;i<inputORI.length();i++)
	{  
        if(inputORI[i]-' '!=0){
             len_token[count_token]++;
        }
		while(inputORI[i]-' '==0){
			i++;
			 if(inputORI[i]-' '!=0){
                count_token++;
                len_token[count_token]++;
            }
        }   
	}
	
	for(int i=0; i<len_token[0]; i++){
        cout<<"11   "<<input[i]<<endl;
        if(int(input[i])==115){     //§PÂ_s 
            cout<<"s is right"<<endl;
            check_strdcl=true;
        }
    }
    
    for(int i=len_token[0]; i<len_token[0]+len_token[1]; i++){  //§PÂ_id 
        cout<<"id is   "<<input[i]<<endl;
        id+=input[i];
        if( 97<=int(input[i])<=111 || int(input[i])==113 || int(input[i])==114 || 116<=int(input[i]<=122) ){
            cout<<"id is right"<<endl;
            check_id=true;
        }
        
        else{
            check_id=false;
        }
    }
	
	cout<<"the complete id is "<<id<<endl;
	
	for(int i=len_token[0]+len_token[1]; i<len_token[0]+len_token[1]+len_token[2]; i++){   //§PÂ_string 
	       cout<<"string is "<<input[i]<<endl;
            if(int(input[i])==34){
                cout<<"check_l_quote is true"<<endl;
                check_l_quote=true;
                i++;
            }
            
            if(check_l_quote){
                cout<<"I'm here"<<endl;
                if( 97<=int(input[i])<=111 || int(input[i])==113 || int(input[i])==114 || 116<=int(input[i]<=122) ){ //§PÂ_ a-o q r t-z 
                    cout<<"check_string is true"<<endl;
                    
                    check_string=true;
                }
                
                else if( int(input[i])==34 ){
                    cout<<"check_r_quote is true"<<endl;
                    
                    check_r_quote=true;  
                }
                
                else{
                    cout<<"string is wrong"<<endl;
                    check_string=false;
                    check_r_quote=false;
                    check_l_quote=false;
                    break;
                }
            }
    }
    int print_position = len_token[0]+len_token[1]+len_token[2];
    
    if(input[print_position]==112){
        cout<<"check_print is true"<<endl;
        check_print=true;
    }
    
   // int print_position = len_token[0]+len_token[1]+len_token[2];
    
	cout<<len_token[0]<<endl;
	cout<<len_token[1]<<endl;
	cout<<len_token[2]<<endl;
	cout<<len_token[3]<<endl;
	cout<<len_token[4]<<endl;
	/*for(int i=0; i<input.length(); i++){
        if(int(input[i])==115){     //§PÂ_s 
            check_strdcl=true;
        }    
        
        else if( 97<=int(input[i])<=111 || int(input[i])==113 || int(input[i])==114 || 116<=int(input[i]<=122) ){     //§PÂ_ a-o q r t-z 
            id+=input[i];
        }
        
    }*/
	
    system("pause");
	return 0;
}
