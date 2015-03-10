#include<stdio.h>;
#include<stdlib.h>
#include <ctype.h>

int main(){
	char inputString[20];

	printf("Plase input: \n");
	gets(inputString);

	int count = 0;
	

//	while(inputString[count] != ' '){
	printf("id	");
	while(true){
		if(isalnum(inputString[count]) != 0 && inputString[count] != ' '){
			printf("%c",inputString[count]);
			//idString[innercount] = inputString[count];
			count++;
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
	
	int j;
	for(j = 0 ; j < 9 ; j++){
		if(isdigit(inputString[j]) != 0 && inputString[j] != ' '){
			printf("%c",inputString[j]);
			
		}
	}
		
		
	
	

	system("PAUSE");
	return 0;
}
