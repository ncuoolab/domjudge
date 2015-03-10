#include<iostream> 
#include<string> 
#include<cstdlib> 
using namespace std; 
  
bool STRDCL(string s){ 
    if(s.length() == 1){ 
        if(s[0] == 115){ 
            return true; 
        } 
        else{ 
            return false; 
        } 
    } 
    else{ 
        return false; 
    } 
} 
  
bool ID(string id){ 
    if(id.length() == 1){ 
        if(id[0] >= 97 && id[0] <= 111){ 
            return true; 
        } 
        else if(id[0] >= 113 && id[0] <= 114){ 
            return true; 
        } 
        else if(id[0] >= 116 && id[0] <= 122){ 
            return true; 
        } 
        else{ 
            return false; 
        } 
    } 
    else{ 
        return false; 
    } 
} 
  
bool QUOTE(string Quote){ 
    if(Quote.length() == 1){ 
        if((int)Quote[0] == 34){ 
            return true; 
        } 
        else{
			cout << "false 1";
            return false; 
        } 
    } 
    else{
		cout << "false 2";
        return false; 
    } 
} 
  
bool STRING(string String){ 
    bool valid_String = true; 
    for(int i = 0 ; i < String.length() ; i++){ 
        if(String[i] >= 97 && String[i] <= 112){ 
        } 
        else if(String[i] >= 65 && String[i] <= 90){ 
        } 
        else if(String[i] >= 48 && String[i] <= 57){ 
        } 
        else{ 
            valid_String == false; 
        } 
    } 
    return valid_String;  
} 
  
bool PRINT(string Print){ 
    if(Print.length() == 1){ 
        if(Print[0] == 112){ 
            return true; 
        } 
        else{ 
            return false; 
        } 
    } 
    else{ 
        return false; 
    } 
} 
  
  
int main(){ 
    string input , Strdcl , Id_1 , Id_2 , Quote_1 , Quote_2 , String = "", Print; 
	int index = 0;
	getline( cin , input );
	Strdcl = input[index];
    if(STRDCL(Strdcl)){
		index = 2;
		Id_1 = input[index];   	
        if(ID(Id_1)){
			index++;
			while(input[index] == 32){
				index++;
			}
			Quote_1 = input[index];        
            if(QUOTE(Quote_1)){ 
				index++;
				while(input[index] == 32){
					index++;
				}
				for(int i = index ; i < input.length() ; i++){
					if(input[i] != 34){
						String = String + input[i];
						index = i;
					}				
				}                                
                if(STRING(String)){ 
					index++;
					while(input[index] == 32){
						index++;
					}
					Quote_2 = input[index]; 
					cout << index;
					cout << Quote_2;
                    if(QUOTE(Quote_2)){ 
                        cin >> Print; 
                        if(PRINT(Print)){ 
                            cin >> Id_2; 
                            if(ID(Id_2)){ 
                                cout << "strdcl " << Strdcl << "\n" << "id " << Id_1 << "\n" << "quote " << Quote_1 << "\n" << "string " << String << "\n" << "quote " << Quote_2 << "\n" << "print " << Print << "\n" << "id " << Id_2;  
                            } 
                            else{ 
                                cout << "valid input 1"; 
                            } 
                        } 
                        else{ 
                            cout << "valid input 2"; 
                        } 
                    } 
                    else{ 
                        cout << "valid input 3"; 
                    } 
                }  
                else{ 
                    cout << "valid input 4"; 
                } 
            }      
            else{ 
                cout << "valid input 5"; 
            } 
        }    
        else{ 
            cout << "valid input 6"; 
        } 
    }
    else{ 
        cout << "valid input 7"; 
    } 

    system("pause"); 
    return 0; 
}