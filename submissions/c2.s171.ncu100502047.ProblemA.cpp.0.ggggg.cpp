#include<stdio.h>;
#include<stdlib.h>
#include <ctype.h>
#include <string.h>

int main(){

	char inputString[20];
	int count = 0;
    int errorscount = 0;
    char idString;
    char digitString[20];
    char assignString;
/*
    int k;
    for(k=0;k<20;k++){
        inputString[k] = ' ';
        digitString[k] = ' ';
    }
*/
	gets(inputString);

    int i ;
    for(i = 0; i < 20 ;i++){

        if(isalpha(inputString[count]) != 0 && inputString[count] != ' ' && errorscount <= 1){
            idString = inputString[count];
            count++;
            errorscount++;
        }
        else if(inputString[count] == ' ' && errorscount == 1){
                break;
        }
        else if(inputString[count] == ' ' && errorscount < 1){
                count++;
        }else{
            printf("valid input");
            return 0;
            break;
        }

    }



          while(true){
            char ass = inputString[count];
            if(ass == ' '){
                count++;
            }else{
             switch(ass){
                    case '=':
                    assignString = '=';
                    count++;
                    break;

                    default:
                    printf("valid input");
                    return 0;
                    break;

                }
               break;
            }
        }


    int j = 0;
	while(true){

        if(inputString[count] == ' ' && count < 20 ){
            count++;
        }else{
            while(count < 20){
                if(isdigit(inputString[count]) != 0 && inputString[count] != ' '){
                    digitString[j] = inputString[count];
                    j++;
                    count++;
                }else if(inputString[count] == ' '){
                    count++;
                }else if(inputString[count] == '\0'){
                    break;
                }else{
                    printf("\nvalid input");
                    return 0;
                }
            }
            break;
        }

	}

	if(errorscount == 1){
        printf("id %c",idString);
    }

        printf("\nassign %c", assignString);

        printf("\ninum %s",digitString);



	return 0;
}
