#include <string>
#include <iostream>
using namespace std ;

int main(){
    string input = "";
    string token = "";
    string result= "";
    //cout << "enter input:";
    int endCortol=0;
    int step = 0;
    while(endCortol==0){
        cin >> input;
        if(step == 0){//level
            if(input[0]=='l'&&input.length()>=2){
                token += "l";
                for(int i = 1;i<input.length();i++){
                    if(input[i]-'0'<0 | input[i]-'0'>9){
                        cout<<"invalid input";
                        return 0;
                    }
                     token += input[i];
                }
                result += "Level " +token+"\n";
                token = "";
                step = 1;
            }else{
                cout<<"invalid input";
                return 0;
            }
        }
        else if(step==1){//id
            if(input[0]-'0'>=0 && input[0]-'0'<=9){//CID
                token+=input[0];
                for(int i = 1;i<input.length();i++){
                    if(input[i]-'0'<0 | input[i]-'0'>9){
                        cout<<"invalid input";
                        return 0;
                    }
                    token += input[i];
                }
                result += "Cid " +token +"\n";
                token = "";
                step = 2;
            }else if(input[0]-'A'>=0&&input[0]-'Z'<=0){//FN
                token+=input[0];
                for(int i = 1;i<input.length();i++){
                    if(input[i]-'a'<0|input[i]-'z'>0){
                        cout<<"invalid input";
                        return 0;
                    }
                    token += input[i];
                }
                result += "FirstName " +token +"\n";
                token = "";
                step = 3;
            }
        }else if(step == 3){//LN
            if(input[0]-'a'>=0&&input[0]-'z'<=0){
                if(input[0]!='b'){
                    token +=input[0];
                    for(int i = 1;i<input.length();i++){
                        if(input[0]=='b'|input[0]-'a'<0|input[0]-'z'>0){
                            cout<<"invalid input";
                            return 0;
                        }
                        token += input[i];
                    }
                    result += "LastName " +token +"\n";
                    token = "";
                    step = 2;
                }
            }
        }else if(step == 2){//battle
            if(input[0]!='b'|input.length()!=1){
                cout<<"invalid input";
                return 0;
            }
            result += "battle b\n";
            step = 4;
        }else if(step==4){//after battle ID
            if(input[0]-'0'>=0 && input[0]-'0'<=9){//CID
                token+=input[0];
                for(int i = 1;i<input.length();i++){
                    if(input[i]-'0'<0 | input[i]-'0'>9){
                        cout<<"invalid input";
                        return 0;
                    }
                    token += input[i];
                }
                result += "Cid " +token +"\n";
                token = "";
                //step = 2;
                endCortol = 1;
            }else if(input[0]-'A'>=0&&input[0]-'Z'<=0){//FN
                token+=input[0];
                for(int i = 1;i<input.length();i++){
                    if(input[i]-'a'<0|input[i]-'z'>0){
                        cout<<"invalid input";
                        return 0;
                    }
                    token += input[i];
                }
                result += "FirstName " +token;
                token = "";
                step = 5;
            }
        }else if(step == 5){//after battle LN
            if(input[0]-'a'>=0&&input[0]-'z'<=0){
                if(input[0]!='b'){
                    token +=input[0];
                    for(int i = 1;i<input.length();i++){
                        if(input[0]=='b'|input[0]-'a'<0|input[0]-'z'>0){
                            cout<<"invalid input";
                            return 0;
                        }
                        token += input[i];
                    }
                    result += "LastName " +token;
                    token = "";
                    endCortol = 1;
                }
            }
        }
    }
    if(endCortol==1)
        cout<<result;
    return 0;
}
