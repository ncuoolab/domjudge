#include<iostream>
#include<string>
using namespace std;


string Match_id(string s , int id_index , string check_id){
	string answer_id = "id ";
	bool valid = true;
	
	for(int i = 0 ; i <= id_index ; i++){
		for(int j = 0 ; j < 53  ; j++){
			if(s[i] == check_id[j]){
				answer_id = answer_id + s[i];
			}
		}
		if(answer_id.length() < (i + 4) ){
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
string Match_Para(string s , int first , int last , string check_para ){
	string answer_para = "para ";
	bool valid = true;

	if(last == first){
		return answer_para;
	}
	else{	
		for(int i = first ; i <= last ; i++){
			for(int j = 0 ; j < 63 ; j++){
				if(s[i] == check_para[j]){
					answer_para = answer_para + s[i];
				}
			}
			if(answer_para.length() < (6 + i - first) ){
				valid = false;
			}
		}

		if(valid == true){
			return answer_para;
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
	string check_id ="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_";
	string check_para = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_";
	int id_index , Lparenthesis_index , Para_index , Rparenthesis_index;
	cin >> input;
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
	id = Match_id(input , id_index , check_id);
	if(id == "Invalid input"){
		answer_valid = false;
	}
	
	Lparenthesis = Match_Lparenthesis(input , Lparenthesis_index);
	
	Para = Match_Para(input , Lparenthesis_index + 1  , Para_index , check_para);
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
	


	system("pause");
	return 0;
}