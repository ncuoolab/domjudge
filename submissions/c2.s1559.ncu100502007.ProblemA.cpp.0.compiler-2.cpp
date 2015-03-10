#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;


int main(){
    string s1,s2,s3,s5,s6;
    string right;
    string wrong;
    char c1,c2,c4,c5,c6;
    cin >> c1;
    cin >> s1;
    if(c1 == 'a'||c1 == 'b'||c1 == 'c'||c1 == 'd'||c1 == 'e'||c1 == 'f'||c1 == 'g'||c1 == 'h'||c1 == 'i'||c1 == 'j'||c1 == 'k'||c1 == 'l'||c1 == 'm'||c1 == 'n'||c1 == 'o'||c1 == 'p'||c1 == 'q'||c1 == 'r'||c1 == 's'||c1 == 't'||c1 == 'u'||c1 == 'v'||c1 == 'w'||c1 == 'x'||c1 == 'y'||c1 == 'z'){
        if(s1 == ""){
			right="id "+c1;
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

    /*cin >> c5;
    cin >> s5;
    if(c5 == '0'||c5 == '1'||c5 == '2'||c5 == '3'||c5 == '4'||c5 == '5'||c5 == '6'||c5 == '7'||c5 == '8'||c5 == '9'){
        right=right+"\ncid "+c5+s5;
    }
    else{
        right=right+"\nFirstName "+c5+s5;
        cin>>s6;
        right=right+"\nLastName "+s6;
    }*/
    if(wrong == ""){
        cout<<right;
    }
    else{
        cout<<wrong;
    }

    system("pause");
    return 0;

}


