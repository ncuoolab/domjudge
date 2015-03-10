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
			right="id "+id+"\n";
		}
		else{
			wrong="valid input\n";
		}
	}
	else{
		wrong="valid input\n";
	}

    cin >> c;

    if(c == '='){
        right=right+"assign "+c+"\n";
    }
    else{
		wrong="valid input\n";
    }
	cin >> num;
    right=right+"inum "+num+"\n";

    if(wrong == ""){
        cout<<right;
    }
    else{
        cout<<wrong;
    }

    return 0;
}


