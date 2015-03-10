#include <iostream>
#include<string>
#include <cstdlib>
using namespace std;



int main(){
    string input;
    string s = "";
    string empty = "";
    int i = 0;
    int quoteTemp = 0;
    string id = "";
    string sstring = "";
    string output[10];
    int outputtemp = 0;

    while(cin>>input){
        s = s + input;
    }

    if(s[i] == 's'){
        output[outputtemp] = empty + "strdcl " + s[i] ;
        outputtemp++;
        i++;
	}else{
		cout<<"valid input"; return 0;
	}

    if(s[i]>='a' && s[i]<='o' || s[i]=='q' ||s[i]=='r' || s[i]>='t' && s[i]<='z'){
        output[outputtemp] = empty +  "id " + s[i] ;
        outputtemp++;
        i++;
    }else{
		cout<<"valid input"; return 0;
	}

	if (s[i] == '\"'){
        output[outputtemp] = empty +  "quote " + s[i];
        outputtemp++;
        i++;

		while(s[i]>='a' && s[i]<='z' || s[i]>='A' && s[i]<='Z' || s[i]>='0' && s[i]<='9'){
            sstring = empty +  sstring + s[i];
            i++;
        }

		if(s[i] == '\"'){

			output[outputtemp] = empty + "string "+sstring;

			outputtemp++;
            output[outputtemp] = empty +  "quote " + s[i];
            outputtemp++;
            i++;
        }else{
			cout<<"valid input";
            return 0;
        }

    }else{
		cout<<"valid input"; return 0;
	}

	if(s[i] == 'p'){

		output[outputtemp] = empty + "print " + s[i] ;
        outputtemp++;
        i++;
    }else{
		cout<<"valid input"; return 0;
	}


	if(s[i]>='a' && s[i]<='o' || s[i]=='q' ||s[i]=='r' || s[i]>='t' && s[i]<='z'){
        output[outputtemp] = empty +  "id " + s[i] ;
        outputtemp++;
        i++;
    }else{
		cout<<"valid input"; return 0;
	}


	if(s[i]!='\0'){
		cout<<"valid input"; return 0;
	}


    for(int j=0; j<outputtemp ; j++){
        cout<<output[j]<<endl;
    }
    system("pause");

    return 0;
}
