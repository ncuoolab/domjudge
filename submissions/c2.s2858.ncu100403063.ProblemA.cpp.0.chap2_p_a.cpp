#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

int main(){
    string id,num;
    string right;
    string wrong;
    char c;
    cin >> id;
	if(id.length() == 1){
		if(id == "a"||id == "b"||id == "c"||id == "d"||id == "e"||id == "f"||id == "g"||id == "h"||id == "i"||id == "j"||id == "k"||id == "l"||id == "m"||id == "n"||id == "o"||id == "p"||id == "q"||id == "r"||id == "s"||id == "t"||id == "u"||id == "v"||id == "w"||id == "x"||id == "y"||id == "z"){
			right="id "+id;
		}
		else{
			wrong="valid input";
		}
	}
	else{
		wrong="valid input";
	}

    cin >> c;

    if(c == '='){
        right=right+"\nassign "+c;
    }
    else{
		wrong="valid input";
    }
	cin >> num;
    right=right+"\ninum "+num;

    if(wrong == ""){
        cout<<right;
    }
    else{
        cout<<wrong;
    }
    system("pause");
    return 0;
}


