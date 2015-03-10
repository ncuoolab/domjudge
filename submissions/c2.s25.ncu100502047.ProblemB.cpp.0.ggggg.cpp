#include<stdio.h>;
#include<stdlib.h>
#include <ctype.h>

int main(){
	char inputString[10];
	char *id = "id";
	char *assign = "=";
	char *inum = "inum";

	printf("Plase input: \n");
	gets(inputString);

	int count = 0;
	int innercount = 0;
	char idString[10];
	char assignChar;
	char inumString[10];

//	while(inputString[count] != ' '){
	printf("%s	", id);
	while(true){
		if(isalnum(inputString[count]) != 0 && inputString[count] != ' '){
			printf("%c",inputString[count]);
			//idString[innercount] = inputString[count];
			count++;
			innercount++;
			break;
		}else{
			printf("invalid input");
			break;
		}
	}
// }	
//	printf("%s %s",id, idString);
	count = 0;

	
	while(true){
			if(inputString[count] == '='){
			printf("\nassign	");
			printf("=");
			break;
		}
		count++;
	}

	count = 0;
	printf("\ninum	");
	while (true){
		if(count == 9){
			break;
		}else{
			if(isdigit(inputString[count]) != 0 && inputString[count] != ' '){
				printf("%c",inputString[count]);
				count++;
			
			}else{
				count++;
				//printf("\ninvalid input");
				
			}
		}
	}
	

	system("PAUSE");
	return 0;
}
