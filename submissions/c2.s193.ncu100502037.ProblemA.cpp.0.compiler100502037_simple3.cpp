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
    while(line[i]!= '\0' ) //Ū�J�ϥΪ̿�J
    {
            if(line[i] == '.'){
                //cout << "valid input: ."<< endl;
                return -1;
            }

            else if(line[i]==' '){

                //continue;
            }


            else if(line[i] >='a'&& line[i]<='z'){//�P�_�O�_���X�kid   [a-z]
                ch[is_another_id] = line[i];
                //cout << "id++"<< endl;
                id++;
                is_another_id++;
                if(id != 1) { // ��J�j��@�ӡA�Τ֩�@�Ӧr�������X�k
                    //cout<< "valid input: id " << endl;
                    return -1;
                }
            }

            else if (line[i] == '='){
                //cout << "I am equal"<< endl;
                equ++;

                //�b=�e���P�_�e��id�O�_�X�k
                if(id != 1) { // ��J�j��@�ӡA�Τ֩�@�Ӧr�������X�k
                    //cout<< "valid input: id " << endl;
                    return -1;
                }
                if(num> 0){// = �e������X�{�Ʀr
                    //cout<< "valid input: id num " << endl;
                    return -1;
                }

                if(equ != 1){
                    return -1;
                }
                id = 0; // =����id �k�s
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
    if(num>0 && id >0){ //id��num ����P�ɥX�{
        //cout<< "valid input: id num " << endl;
        return -1;
    }

    //cout<< "i = "<< i << endl;
    return 1; //���T��J�A�i�I�sparser�L�X
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


