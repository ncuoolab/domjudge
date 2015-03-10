#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char inputstring[20];
    char idFirst[10];
    char idsecond[10];
    char idstring[10];
    char *lparOutput;
    char *rparOutput;

    int isInum = 0;
    int isIdsecond = 0;
  //  int isIdFirst = 0;

    char *answer[8];

    gets(inputstring);

    int count = 0;
    int idCount = 0;

    char currentChar = inputstring[count];

    while(currentChar != '\0'){
        if(currentChar == ' '){
            count++;
            currentChar = inputstring[count];
        }else{
            break;
        }
    }
     while(currentChar != '\0'){
                if(isalpha(currentChar) || currentChar == '_' ){
                    idFirst[idCount] = currentChar;
                    count++;
                    idCount++;
                    currentChar = inputstring[count];
                }else if(currentChar == ' '){
                    idFirst[idCount] = '\0';
                    break;
                }else{
                    if(currentChar == '('){
                        idFirst[idCount] = '\0';
                        break;
                    }else{
                        printf("invalid input");
                        return 0;
                    }
                }
    }


    while(currentChar != '\0'){
        if(currentChar == ' '){
            count++;
            currentChar = inputstring[count];
        }else{
            break;
        }
    }

    while(currentChar != '\0'){
        if(currentChar == '('){
            lparOutput = "lparenthesis (";
            count++;
            currentChar = inputstring[count];
            break;
        }else{
            printf("invalid input");
            return 0;
        }
    }
    while(currentChar != '\0'){
        if(currentChar == ' '){
            count++;
            currentChar = inputstring[count];
        }else{
            break;
        }
    }

    idCount = 0;

    while(currentChar != '\0'){
        if(isInum == 0 && isalpha(currentChar)){
            break;
        }
        if(isdigit(currentChar)){
                isInum = 1 ;
                    idsecond[idCount] = currentChar;
                    count++;
                    idCount++;
                    currentChar = inputstring[count];
        }else if(currentChar == ' '){
            idsecond[idCount] = '\0';
            break;
        }else{
            if(currentChar == ')'){
            idsecond[idCount] = '\0';
                break;
            }else{
            printf("invalid input");
            return 0;
            }

        }
    }

    idCount = 0;

    while(currentChar != '\0'){
     if(isInum == 1){
        break;
     }

     if(isalpha(currentChar)){
                    isIdsecond = 1 ;
                        idstring[idCount] = currentChar;
                        count++;
                        idCount++;
                        currentChar = inputstring[count];
            }else if(currentChar == ' '){
                idstring[idCount] = '\0';
                break;
            }else{
                if(currentChar == ')'){
                        idstring[idCount] = '\0';
                    break;
                }else{
                printf("invalid input");
                return 0;
                }
            }
    }

    while(currentChar != '\0'){
        if(currentChar == ' '){
            count++;
            currentChar = inputstring[count];
        }else{
            break;
        }
    }

int isIn = 0;

    while(currentChar != '\0'){
        if(currentChar == ')'){
            if(isIn > 1){
                 printf("invalid input");
                return 0;
            }
            isIn+=2;
            rparOutput = "rparenthesis )";
            count++;
            currentChar = inputstring[count];
        }else if(currentChar == ' '){
            count++;
            currentChar = inputstring[count];
        }else{
            printf("invalid input");
            return 0;
        }
    }

    printf("id %s\n", idFirst);
    printf("%s\n",lparOutput);
    if(isInum == 1){
        printf("inum %s\n", idsecond);
    }else if(isIdsecond == 1){
        printf("id %s\n", idstring);
    }

    printf("%s", rparOutput);

    system("PAUSE");
    return 0;
}
