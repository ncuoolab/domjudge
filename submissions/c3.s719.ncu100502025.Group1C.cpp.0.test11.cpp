#include<iostream>
#include<string>
using namespace std;


string Match_id(string s , int id_index){
	string answer_id = "id ";
	bool valid = true;
	
	for(int i = 0 ; i <= id_index ; i++){
		if(s[i] >= 66 && s[i]<= 91) {
			answer_id = answer_id + s[i];
		}
		else if(s[i] >= 97 && s[i]<= 122){
			answer_id = answer_id + s[i];
		}
		else if(s[i] == 96){
			answer_id = answer_id + s[i];
		}		
		else{
			valid = false;
		}
	}
	if(valid == true){
		return answer_id;
	}
	else if(valid == false){
		return "Invalid input";
	}
}
string Match_Lparenthesis(string s , int Lparenthesis_index ){
	string answer_Lparenthesis = "lparenthesis ";
	answer_Lparenthesis = answer_Lparenthesis + s[Lparenthesis_index];
	return answer_Lparenthesis;
}
string Match_Para(string s , int first , int last){
	string answer_number  = "inum ";
	string answer_id  = "id ";
	bool valid = true;
	bool num = false;
	bool id = false ;

	if(last == first){
		return answer_number;
	}
	else{	
		for(int i = first ; i <= last ; i++){
			if(s[i] >= 48 && s[i]<= 57){
				answer_number = answer_number + s[i];
				num = true;
			}
			else if(s[i] >= 66 && s[i]<= 91){
				answer_id = answer_id + s[i];
				id = true;
			}
			else if(s[i] >= 97 && s[i]<= 122){
				answer_id = answer_id + s[i];
				id = true;
			}
			else if(s[i] == 96){
				answer_id = answer_id + s[i];
				id = true;
			}
			else{
				valid = false;
			}
		}
		if(valid == true){
			if(num == true){
				if(id == true ){
					return answer_number + "\n" + answer_id;
				}
				else{
					return answer_number;
				}
			}
			else{
				if(id == true){
					return answer_id;
				}
			}
		}
		else if(valid == false){
			return "Invalid input";
		}
	}
}

string Match_Rparenthesis(string s , int Rparenthesis_index ){
	string answer_Rparenthesis = "rparenthesis ";
	answer_Rparenthesis = answer_Rparenthesis + s[Rparenthesis_index];
	return answer_Rparenthesis;
}


int main(){

	string input , id , Lparenthesis , Para , Rparenthesis;
	bool answer_valid = true;
	int id_index , Lparenthesis_index , Para_index , Rparenthesis_index;
	getline(cin , input);
	//cin >> input;
	for(int i = 0 ; i < input.length() ; i++ ){
		if(input[i] == '('){
			id_index = i - 1 ;
			Lparenthesis_index = i;
		}
		else if(input[i] == ')'){
			Para_index = i - 1;
			Rparenthesis_index = i;
		}	
	}
	id = Match_id(input , id_index );
	if(id == "Invalid input"){
		answer_valid = false;
	}
	
	Lparenthesis = Match_Lparenthesis(input , Lparenthesis_index);
	
	Para = Match_Para(input , Lparenthesis_index + 1  , Para_index);
	if(Para == "Invalid input"){
		answer_valid = false;
	}

	Rparenthesis = Match_Rparenthesis(input , Rparenthesis_index);


	if(answer_valid == true){
		cout << id << "\n" << Lparenthesis << "\n" << Para << "\n" << Rparenthesis << "\n";
	}
	else if(answer_valid == false){
		cout << "Invalid input";
	}


	//system("pause");
	return 0;
}