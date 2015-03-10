#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;
string inputORI, input;

int main()
{
    
    bool check_strdcl=false;
    bool check_id=false;
    bool check_l_quote=false;
    bool check_r_quote=false;
    bool check_string=false;
    bool check_print=false;
    bool check_id_2=false;
    string input, inputORI;
    string content;
    char id_1;
    //getline(cin,inputORI);
    
    while(cin>>inputORI){
        input+= inputORI; 
    }
    
	
	for(int i=0;i<input.length();i++){
        
        //cout<<"i is "<<i<<" input[i] is "<<input[i]<<endl;
        
        if( i==0 && input[i]=='s'){
            check_strdcl=true;
            //cout<<"check_strdcl is true"<<endl;   
        }
    
        
        else if( i==1 && (input[i]>='a' && input[i]<='o') || (input[i]>='t' && input[i]<='z') || input[i]=='q' || input[i]=='r' ){
            id_1=input[i];
            check_id=true;
            //cout<<"check_id is true"<<endl;   
        }
        
        
        else if(i==2 && input[i]=='"'){
            check_l_quote=true;
            //cout<<"check_l_quote is true"<<endl; 
        }
        
        
        else if(check_l_quote){
            //cout<<"I'm in checking l quote"<<endl;
            
            if(input[i]=='"'){
                //cout<<"Wow check_r_quote is true"<<endl;
                content="";
                check_r_quote=true;
                i++;    
            }
            
            else{
                while( input[i] != '"' && i<input.length() ){
                    if( (input[i]>='a'&&input[i]<='z') || (input[i]>='A' && input[i]<='Z') || (input[i]>='0' && input[i]<='9') ){ //§PÂ_ a-o q r t-z 
                        //cout<<"check_string is true"<<endl;
                        content+=input[i];
                        check_string=true;
                        i++;
                    }    
                    
                    else{
                        //cout<<"check_string is false"<<endl; 
                        check_string=false;
                        break;
                    }
                }
                
                if(input[i] == '"'){
                    //cout<<"check_r_quote is true"<<endl;
                    check_r_quote=true;  
                    i++;  
                }
                else
                    break;
            }
               
        }
        
        
        if(check_l_quote && check_r_quote ){
            if(input[i]=='p'){
                //cout<<"check_print is true"<<endl;
                check_string=true;
                check_print=true;
                i++;
            }    
            
            else{
                check_print=false;
                break;    
            }
        }
        
        if(check_print){
            if( input[i] == id_1 ){
                check_id_2=true;  
                i++;
                //cout<<"check_id_2 is true"<<endl;
            }
            
            else{
               check_id_2=false;  
               break;    
            }
        }
        
            
    }
    
    /*cout<<"check_strdcl "<<check_strdcl<<endl;
    cout<<"check_id "<<check_id<<endl;
    cout<<"check_l_quote "<<check_l_quote<<endl;
    cout<<"check_r_quote "<<check_r_quote<<endl;
    cout<<"check_string "<<check_string<<endl;
    cout<<"check_print "<<check_print<<endl;
    cout<<"check_id_2 "<<check_id_2<<endl;*/
    
    if( check_strdcl && check_id && check_l_quote && check_r_quote && check_string && check_print&&check_id_2){
        cout<<"strdcl s"<<endl;
        cout<<"id "<<id_1<<endl;
        cout<<"quote \""<<endl;
        cout<<"string "<<content<<endl;
        cout<<"quote \""<<endl;
        cout<<"print p"<<endl;
        cout<<"id "<<id_1<<endl;
    }
    
    else{
        cout<<"valid input";    
    }
    
    system("pause");
	return 0;
}
