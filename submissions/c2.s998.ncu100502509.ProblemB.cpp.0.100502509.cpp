#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>

using namespace std;


struct token_Character{
    string character;
    string name;
};

vector<token_Character> token;
string type_token="";
bool inBrace=false;

bool grammar_Check(string s){
    if (s=="1234352"){
        return true;
    }

    else{
        return false;
    }
}

bool terminal_Check(string s){
    int count=0;
    string temp;
    while(count<s.length()){
        if (!inBrace){
            if (s.length()==1 && s[count]=='s'){
                type_token.push_back('1');
                token_Character t;
                t.character="strdcl";
                t.name="s";
                token.push_back(t);
                return true;
            }

            else if(s.length()==1 && s[count]=='p'){
                type_token.push_back('5');
                token_Character t;
                t.character="print";
                t.name="p";
                token.push_back(t);
                return true;
            }

            else if(s[count]=='"'){
                type_token.push_back('3');
                token_Character t;
                t.character="quote";
                t.name="\"";
                token.push_back(t);
                inBrace=true;
                count++;
            }

            else if(s.length()==1 || s[count+1]=='"' && (s[count]>='a'&& s[count]<='o') || (s[count]>='t'&& s[count]<='z') || s[count]=='q' || s[count]=='r'){
                type_token.push_back('2');
                token_Character t;
                t.character="id";
                t.name=s[count];
                token.push_back(t);
                count++;
            }

            else{
                return false;
            }
        }

        else{
            if (s[count]=='"'){
                count++;
                type_token.push_back('3');
                token_Character t;
                t.character="quote";
                t.name="\"";
                token.push_back(t);
                inBrace=false;
            }

            else if((s[count]>='a'&& s[count]<='z') || (s[count]>='A'&& s[count]<='Z') || (s[count]>='0'&& s[count]<='9')){
                temp.push_back(s[count]);

                if (count==s.length()-1 || s[count+1]=='"'){
                    type_token.push_back('4');
                    token_Character t;
                    t.character="string";
                    t.name=temp;
                    token.push_back(t);
                    temp.clear();
                }

                count++;
            }

            else{
                return false;
            }
        }
    }

    return true;
}

int main(){
    vector<string> s;
    int count=0;
    string input;

    while(cin>>input){
        count++;
        s.push_back(input);
        cout<<input<<"\n";
    }

    for(int a=0 ; a<count ; a++){
        if (!terminal_Check(s[a])){
            cout<<"valid input\n";
        }
    }

    if (grammar_Check(type_token)){
        for(int a=0 ; a<type_token.length() ; a++){
            cout<<token[a].character<<" "<<token[a].name<<"\n";
        }
    }

    else{
        cout<<"invalid input\n";
    }

    system("pause");
    return 0;
}
