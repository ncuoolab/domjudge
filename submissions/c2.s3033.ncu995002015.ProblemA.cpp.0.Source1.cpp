#include<iostream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

// id [a-z]
bool IsId(char x){
	if (96 < (int)x && (int)x < 123)
		return true;
	else
		return false;
}

// assign =
bool IsAssign(char x){
	if ((int)x == 61)
		return true;
	else
		return false;
}

// inum [0-9]+
bool IsInum(char x){
	if (47 < (int)x && (int)x < 58)
		return true;
	else
		return false;
}

// Scan token_array
bool TokenScan(string x[]){
	if (x[0] == "id")
		if (x[1] == "assign")
			if (x[2] == "inum" || x[2] == "id")
				if (x[3].empty())
					return true;
	return false;
}

int main(){
	char input[50];
	string token[50];
	string value[50];
	int array_pointer = 0;

	cin.getline(input, 50);

	for (int input_pointer = 0; input_pointer < 50; input_pointer++){
		if (input[input_pointer] == '\0')
			break;
		else if (input[input_pointer] == ' ')
			continue;
		else if (IsId(input[input_pointer])){
			token[array_pointer] = "id";
			value[array_pointer] = input[input_pointer];
			array_pointer++;
		}
		else if (IsAssign(input[input_pointer])){
			token[array_pointer] = "assign";
			value[array_pointer] = input[input_pointer];
			array_pointer++;
		}
		else if (IsInum(input[input_pointer])){
			string temp;
			while (IsInum(input[input_pointer])){
				temp += input[input_pointer];
				input_pointer++;
			}
			if (input[input_pointer] == ' ' || input[input_pointer] == '\0'){
				token[array_pointer] = "inum";
				value[array_pointer] = temp;
				array_pointer++;
			}
			input_pointer--;
		}
		else{
			cout << "invalid input" << endl;
			system("pause");
			return 0;
		}
	}

	if (TokenScan(token)){
		for (int output_pointer = 0; output_pointer < array_pointer; output_pointer++){
			cout << token[output_pointer] << " ";
			cout << value[output_pointer] << endl;
		}
	}
	else
		cout << "invalid input" << endl;

	system("pause");
	return 0;
}
