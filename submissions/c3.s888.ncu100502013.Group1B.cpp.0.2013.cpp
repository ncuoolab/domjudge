#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
    string answer = "";
    bool status = true;
    int counting = 0;
	char input[512];
	cin.getline(input,512);
	if(input[counting]!='l'){
        cout << "invalid input\n";
        system("pause");
        return 0;
	}
	answer += "level l";
	counting++;
	if(input[counting]<48 || input[counting]>57){
        cout << "invalid input\n";
        system("pause");
        return 0;
	}
	string s(1,input[counting]);
	answer += "" + s;
	counting++;
	while(status){
        if(input[counting]>=48 && input[counting]<=57){
            string s(1,input[counting]);
	answer += "" + s;
            counting++;

        }
        else if(input[counting]==32){
            counting++;
            status = false;
        }
        else{
            cout << "invalid input\n";
            system("pause");
            return 0;
        }
	}
	answer += "\n";
	status = true;
	//level comp.
	if(input[counting]>=48 && input[counting]<=57){
	    answer += "cid ";
        string s(1,input[counting]);
	answer += "" + s;
        counting++;
        while(status){
            if(input[counting]<48 || input[counting]>57){
                if(input[counting]==32){
                    counting++;
                    status = false;
                }
                else{
                    cout << "invalid input\n";
                    system("pause");
                    return 0;
                }
            }
            else{
                string s(1,input[counting]);
	answer += "" + s;
                counting++;
            }
        }
        status = true;
	}
	else if(input[counting]>=65 && input[counting]<=90){
	    answer += "FirstName ";
	    string s(1,input[counting]);
	    answer += "" + s;
        counting++;
        while(status){
            if(input[counting]>=97 && input[counting]<=122){
                string s(1,input[counting]);
	answer += "" + s;
                counting++;
            }
            else if(input[counting]==32){
                counting++;
                status = false;
            }
            else{
                cout << "invalid input\n";
                system("pause");
                return 0;
            }
        }
        answer += "\n";
        status = true;
        if(input[counting]>=97 && input[counting]<=122 && input[counting]!=98){
            answer += "LastName ";
            string s(1,input[counting]);
            answer += "" + s;
            counting++;
            while(status){
                if(input[counting]>=97 && input[counting]<=122 && input[counting]!=98){
                    string s(1,input[counting]);
	answer += "" + s;
                    counting++;
                }
                else if(input[counting]==32){
                    counting++;
                    status = false;
                }
                else{
                    cout << "invalid input\n";
                    system("pause");
                    return 0;
                }
            }
            answer += "\n";
            status = true;
        }
        else{
            cout << "invalid input\n";
            system("pause");
            return 0;
        }
	}
	else{
        cout << "invalid input\n";
        system("pause");
        return 0;
	}
	//id comp.
	if(input[counting]!=98){
        cout << "invalid input\n";
        system("pause");
        return 0;
	}
	answer += "battle b\n";
	counting++;
	if(input[counting]!=32){
        cout << "invalid input\n";
        system("pause");
        return 0;
	}
	counting++;
	//battle comp.
	if(input[counting]>=48 && input[counting]<=57){
	    answer += "cid ";
        string s(1,input[counting]);
	answer += "" + s;
        counting++;
        while(status){
            if(input[counting]<48 || input[counting]>57){
                if(input[counting]=='\0'){
                    counting++;
                    status = false;
                }
                else{
                    cout << "invalid input\n";
                    system("pause");
                    return 0;
                }
            }
            else{
                string s(1,input[counting]);
	answer += "" + s;
                counting++;
            }
        }
        status = true;
	}
	else if(input[counting]>=65 && input[counting]<=90){
	    answer += "FirstName ";
	    string s(1,input[counting]);
	answer += "" + s;
        counting++;
        while(status){
            if(input[counting]>=97 && input[counting]<=122){
                string s(1,input[counting]);
	answer += "" + s;
                counting++;
            }
            else if(input[counting]==32){
                counting++;
                status = false;
            }
            else{
                cout << "invalid input\n";
                system("pause");
                return 0;
            }
        }
        answer += "\n";
        status = true;
        if(input[counting]>=97 && input[counting]<=122 && input[counting]!=98){
            answer += "LastName ";
            string s(1,input[counting]);
	answer += "" + s;
            counting++;
            while(status){
                if(input[counting]>=97 && input[counting]<=122 && input[counting]!=98){
                    string s(1,input[counting]);
	answer += "" + s;
                    counting++;
                }
                else if(input[counting]=='\0'){
                    counting++;
                    status = false;
                }
                else{
                    cout << "invalid input\n";
                    system("pause");
                    return 0;
                }
            }
            status = true;
        }
        else{
            cout << "invalid input\n";
            system("pause");
            return 0;
        }
	}
	else{
        cout << "invalid input\n";
        system("pause");
        return 0;
	}
	//id comp. again

	//output
	cout << answer;
	system("pause");
	return 0;
}
