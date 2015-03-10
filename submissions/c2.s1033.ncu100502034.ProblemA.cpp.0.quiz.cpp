#include <string>
#include <iostream>
using namespace std ;

int main(){
    string input = "";
    string token = "";
    string result= "";
    int endCortol=0;
    int step = 0;
    while(endCortol==0){
        cin >> input;
        if(step==0){
            if((input[0]-'a'>=0&&input[0]-'z'<=0)&&(input.length()==1)){
                result+="id "+input +"\n";
                step = 1;
            }else{
                cout<<"valid input";
                break;
            }
        }
        else if(step == 1){
            if(input=="="){
                result+="assign "+input +"\n";
                step =2;
            }else{
                cout<<"valid input";
                break;
            }
        }else if(step == 2){
            if((input[0]-'a'>=0&&input[0]-'z'<=0)&&(input.length()==1)){
                result+="id "+input;
                endCortol = 1;
            }else if(input[0]-'0'>=0 && input[0]-'0'<=9){
                result +="i";
                result +="n";
                result +="u";
                result +="m ";
                result +=input[0];
                for(int i = 1;i<input.length();i++){
                    if(input[i]-'0'>=0 && input[i]-'0'<=9){
                        result+=input[i];
                    }
                    else{
                        cout<<"valid input";
                        break;
                    }
                }
                endCortol = 1;
            }else{
                cout<<"valid input";
                break;
            }
        }

    }
    if(endCortol==1)
        cout<<result<<endl;
    return 0;
}
