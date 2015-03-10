#include<iostream>
#include<cstdlib>
using namespace std;

int main(){
    char input[512];
    cin.getline(input, 512);
    int counting = 0;
    string answer = "";
    bool status = true;

    if(input[counting]!=115){
        cout << "invalid input";
        system("pause");
        return 0;
    }
    answer += "strdcl s\n";
    counting++;
    if(input[counting]!=32){
        cout << "invalid input";
        system("pause");
        return 0;
    }
    counting++;
    //strdcl comp.
    if(input[counting]==112 || input[counting]==115){
        cout << "invalid input";
        system("pause");
        return 0;
    }
    if(input[counting]<97 || input[counting]>122){
        cout << "invalid input";
        system("pause");
        return 0;
    }
    string temp(input+counting,1);
    answer += "id " + temp;
    counting++;
    if(input[counting]!=32){
        cout << "invalid input";
        system("pause");
        return 0;
    }
    answer += "\n";
    counting++;
    //id comp.
    if(input[counting]!=34){
        cout << "invalid input";
        system("pause");
        return 0;
    }
    answer += "quote \"\nstring ";
    counting++;
    while(status){
        if(input[counting]==34){
            answer += "\nquote \"\n";
            counting++;
            status = false;
        }
        else if(input[counting]>=48 && input[counting]<=57){
            string temp2(input+counting,1);
            answer += "" + temp2;
            counting++;

        }
        else if(input[counting]>=65 && input[counting]<=90){
            string temp2(input+counting,1);
            answer += "" + temp2;
            counting++;
        }
        else if(input[counting]>=97 && input[counting]<=122){
            string temp2(input+counting,1);
            answer += "" + temp2;
            counting++;
        }
        else{
            cout << "invalid input";
            system("pause");
            return 0;
        }
    }
    if(input[counting]!=32){
        cout << "invalid input";
        system("pause");
        return 0;
    }
    counting++;
    //Astring comp.
    if(input[counting]!=112){
        cout << "invalid input";
        system("pause");
        return 0;
    }
    answer += "print p\n";
    counting++;
    if(input[counting]!=32){
        cout << "invalid input";
        system("pause");
        return 0;
    }
    counting++;
    //print comp.
    if(input[counting]==112 || input[counting]==115){
        cout << "invalid input";
        system("pause");
        return 0;
    }
    if(input[counting]<97 || input[counting]>122){
        cout << "invalid input";
        system("pause");
        return 0;
    }
    string temp1(input+counting,1);
    answer += "id " + temp1;
    counting++;
    if(input[counting]!='\0'){
        cout << "invalid input";
        system("pause");
        return 0;
    }
    counting++;
    cout << answer;
    system("pause");
    return 0;
}
