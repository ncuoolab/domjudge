#include<cstdlib>
#include<iomanip>
#include<string>
#include<iostream>
using namespace std;

int main(){
	
	char t;
	int step = 0;
	bool quoteCheck = false;
	bool firstStr = true;
	char id;
	string r;
	bool havestring = false;
	
	while(cin >> t){
		
		if(step==0 && t=='s'){r=r+"strdcl s"+"\n"; step++;}
		else if(step==1 &&(((int)t>=97 && (int)t<=111) || ((int)t>=113 && (int)t<=114) || (int)t>=116 && (int)t<=122)){r=r+"id "+t+"\n"; step++; id=t;}
		else if(step==2 && quoteCheck==false && t=='"'){r=r+"\quote \" "; quoteCheck=true; step++;}
		else if(step==3 && firstStr==true && t!='"'){r=r+"string "+t; firstStr=false;}
		else if(step==3 && firstStr==false&& t!='"' && (((int)t>=97&&(int)t<=122)||((int)t>=65&&(int)t<=90))||((int)t>=48&&(int)t<=57)){r=r+t;havestring=true;}
		else if(step==3 && quoteCheck==true && t=='"'){if(havestring=true){r=r+"\n";}r=r+"\quote \" "+"\n"; step++;}
		else if(step==4 && t=='p'){r=r+"print p"+"\n"; step++;}
		else if(step==5 && t==id){r=r+"id "+t+"\n"; break;}
		else{r="valid input";break;}
	}

	cout << r;
	
	

	system("pause");
	return 0;
}