#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
	string intemp;
	string answer = "";
	string input = "";
	int counting = 0;
	bool status = true;
	while(cin >> intemp){
		input += intemp + " ";
	}

	if(input[counting]!=115){
        cout << "valid input";
        system("pause");
        return 0;
    }
    answer += "strdcl s\n";
    counting++;
    cout << input[counting] << endl;
    if(input[counting]!=32 && input[counting]!=13){
        cout << "valid input";
        system("pause");
        return 0;
    }
    counting++;
    //strdcl comp.
    if(input[counting]==112 || input[counting]==115){
        cout << "valid input";
        system("pause");
        return 0;
    }
    if(input[counting]<97 || input[counting]>122){
        cout << "valid input";
        system("pause");
        return 0;
    }
    string atemp;
    atemp = input.substr(counting, 1);
    answer += "id " + atemp;
    counting++;

    if(input[counting]==32 || input[counting]==13){
        counting++;
    }
    answer += "\n";
    //counting++;
    //id comp.
    if(input[counting]!=34){
        cout << "valid input";
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
            atemp = input.substr(counting, 1);
            answer += "" + atemp;
            counting++;

        }
        else if(input[counting]>=65 && input[counting]<=90){
            atemp = input.substr(counting, 1);
            answer += "" + atemp;
            counting++;
        }
        else if(input[counting]>=97 && input[counting]<=122){
            atemp = input.substr(counting, 1);
            answer += "" + atemp;
            counting++;
        }
        else{
            cout << "valid input";
            system("pause");
            return 0;
        }
    }
    if(input[counting]!=32 && input[counting]!=13){
        cout << "valid input";
        system("pause");
        return 0;
    }
    counting++;
    //Astring comp.
    if(input[counting]!=112){
        cout << "valid input";
        system("pause");
        return 0;
    }
    answer += "print p\n";
    counting++;
    if(input[counting]!=32 && input[counting]!=13){
        cout << "valid input";
        system("pause");
        return 0;
    }
    counting++;
    //print comp.
    if(input[counting]==112 || input[counting]==115){
        cout << "valid input";
        system("pause");
        return 0;
    }
    if(input[counting]<97 || input[counting]>122){
        cout << "valid input";
        system("pause");
        return 0;
    }
    atemp = input.substr(counting, 1);
    answer += "id " + atemp;
    counting += 2;
    if(input[counting]){
        cout << "valid input";
        system("pause");
        return 0;
    }
    counting++;
    cout << answer;
	system("pause");
	return 0;
}
