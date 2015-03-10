#include<cstdlib>
#include<iomanip>
#include<string>
#include<iostream>
using namespace std;

int main(){


	
	char t;
	int step = 0;
	string r;
	
	bool firstId = false;
	bool firstNum = false;
	bool haveId = false;
	bool haveNum = false;

	
	while(cin >> t){

		if(step==0 && (  (  ((int)t>=97 && (int)t<=122)) || ((int)t>=65 && (int)t<=90) || (int)t==95  ) ){
			firstId=true ; r=r+"id "+t; step++;
		}
		else if(firstId == true && step==1 && ((((int)t>=97 && (int)t<=122)) || ((int)t>=65 && (int)t<=90) || (int)t==95)){r=r+t;}

		else if(step==1  && (int)t==40){step++ ; r=r+"\n"+"lparenthesis ("+"\n";}

		else if(step==2 && ( ((int)t>=48 && (int)t<=57) || ((int)t>=97 && (int)t<=122) || ((int)t>=65 && (int)t<=90) || ((int)t==95) )){
			if(firstNum == false){firstNum=true ; r=r+"inum "+t;}
			else if(firstNum == true){r=r+t;}
		}

		else if(step==2 && (int)t==41){step++ ; r=r+"\n"+"rparenthesis )"+"\n"; break;}
		else{r="invalid input";break;}
	}

	cout << r << endl;

	

	system("pause");
	return 0;
}