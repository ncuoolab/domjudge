#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;


int main(){
    string s1,s2,s3,s5,s6;
    string right;
    string wrong;
    char c1,c2,c4,c5,c6;
    cin >> s1;
	if(s1.length() == 1){
		if(s1 == "a"||s1 == "b"||s1 == "c"||s1 == "d"||s1 == "e"||s1 == "f"||s1 == "g"||s1 == "h"||s1 == "i"||s1 == "j"||s1 == "k"||s1 == "l"||s1 == "m"||s1 == "n"||s1 == "o"||s1 == "p"||s1 == "q"||s1 == "r"||s1 == "s"||s1 == "t"||s1 == "u"||s1 == "v"||s1 == "w"||s1 == "x"||s1 == "y"||s1 == "z"){
			right="id "+s1;
		}
		else{
			wrong="valid input";
		}
	}
	else{
		wrong="valid input";
	}

    cin >> c2;

    if(c2 == '='){
        right=right+"\nassign "+c2;
    }
    else{
		wrong="valid input";
    }
	cin >> s3;
    right=right+"\ninum "+s3;

    if(wrong == ""){
        cout<<right;
    }
    else{
        cout<<wrong;
    }

    system("pause");
    return 0;

}


