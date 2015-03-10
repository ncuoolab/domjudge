#include <stdio.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include <algorithm>//swap
#include <ctype.h>

using namespace std;

enum token_types{
    ID, ASSIGN, INUM, END, DOT
};

int Scan();
void Parse();

string line;
int  b, c,  equ, id, num, i;
char ch[100];
int is_another_id = 0;

int main() {

    getline(cin, line ,'\n');
    i =0;
    int correct =Scan();

    if( correct == -1)
    {
        cout << "valid input"<< endl;
        return 0;
    }
    else{
        Parse();
        return 0;
    }
}

int Scan(){
    while(line[i]!= '\0' ) //讀入使用者輸入
    {
            if(line[i] == '.'){
                //cout << "valid input: ."<< endl;
                return -1;
            }

            else if(line[i]==' '){

                //continue;
            }


            else if(line[i] >='a'&& line[i]<='z'){//判斷是否為合法id   [a-z]
                ch[is_another_id] = line[i];
                //cout << "id++"<< endl;
                id++;
                is_another_id++;
                if(id != 1) { // 輸入大於一個，或少於一個字母都不合法
                    //cout<< "valid input: id " << endl;
                    return -1;
                }
            }

            else if (line[i] == '='){
                //cout << "I am equal"<< endl;
                equ++;

                //在=前先判斷前面id是否合法
                if(id != 1) { // 輸入大於一個，或少於一個字母都不合法
                    //cout<< "valid input: id " << endl;
                    return -1;
                }
                if(num> 0){// = 前面不能出現數字
                    //cout<< "valid input: id num " << endl;
                    return -1;
                }

                if(equ != 1){
                    return -1;
                }
                id = 0; // =之後id 歸零
                //cout << "equ:"<< equ<< endl;
            }

            else if (isdigit(line[i])){
                //cout << "I am digit"<< endl;
                b = (b*10)+ (line[i] - 0x30) ;
                num++;
            }
            else {
                //cout << "valid input: else"<< endl;
                return -1;
            }
        i++;
    }
    if(num>0 && id >0){ //id跟num 不能同時出現
        //cout<< "valid input: id num " << endl;
        return -1;
    }

    //cout<< "i = "<< i << endl;
    return 1; //正確輸入，可呼叫parser印出
}


void Parse(){

    cout<< "id " << ch[0] << endl;
    cout<< "assign = " << endl;


    if(num>=1){
        cout<< "inum " << b<< endl;
        //cout<< "num "<< num <<  endl;
    }
    else if(is_another_id > 1){
        cout<< "id " << ch[1] << endl;
    }

}

void Stmt(){


}

void Val(){

}


