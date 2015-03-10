#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main(){
	string a;
	int count = 0;
	string out = "";
	getline(cin,a);
	for(int i = 0; i< a.size() ; i++){
		if(a[i] != 32){
			if(97 <= a[i] && a[i] <= 122 && count == 0){
			out = out +"id " + a[i] + "\n";
			count++;
			}
			else if(count == 1 && a[i] == 61){
				out = out + "assign " + a[i] + "\n";
				count++;
			}
			else if(count == 2 && 97 <= a[i] && a[i] <= 122){
				out = out + "id " + a[i];
			}
			else if(count == 2 &&  48 <= a[i] && a[i] <= 57){
				out = out + "inum " + a[i];
				count ++;
			}
			else if(count == 3 &&  48 <= a[i] && a[i] <= 57){
				out = out + a[i];
			}
			else if(a[i] =='\n'||a[i]=='\r'){
				break;
			}
			else{
				out="valid input";
				break;
			}
		}

	}
	cout<<out;



	system("pause");
	return 0;
}
