%{
#include <string.h>
#define bool int
#define true 1
#define false 0

char line[1000] = "";
int validNums = 0;
bool isPrevDot = false;
%}
number          [0-9]+
dot             "."
other           .|"\t"|"\n"|"\r"
%%
{number} {
    if(validNums==0 || isPrevDot){
		int num = 0;
		int txtPtr = 0;
		if(yytext[0]=='0' && yytext[1]!='\0'){
			//not allowed leading zeroes
			num = -1;
		}else{
			while(yytext[txtPtr] != '\0'){
				num *= 10;
				num += yytext[txtPtr] - '0';
				txtPtr++;
			}
		}
		
		if(num>=0 && num<=255){
			//OK: add number
			//printf("OK: %d", num);
			strcat(line, yytext);
			validNums++;
		}else{
			//invalid: the number is out of range
			//printf("XX: %d", num);
			validNums = 0;
			isPrevDot = false;
			strcpy(line, "");
		}
		isPrevDot = false;
	}else{
		//invalid: double numbers together with other separators
		validNums = 0;
		isPrevDot = false;
		strcpy(line, "");
	}
}
{dot} {
	if(isPrevDot){
		//invalid: double dots directly together
		validNums = 0;
		isPrevDot = false;
		strcpy(line, "");
	}else if(validNums>0){
		//OK: add dot
		strcat(line, yytext);
		isPrevDot = true;
	}
}
{other} {
	if(validNums==4){
		printf("%s\n", line);
	}
	//reset the statistic values for the next matches if success
	//or invalid if the IP address does not complete yet
	//and then other symbols are detected
	validNums = 0;
	isPrevDot = false;
	strcpy(line, "");
}
%%
int main(int argc, char *argv[]) {
	yylex();
	if(validNums==4){
		//Here works if the EOF is right after a correct IP format.
		printf("%s\n", line);
	}
    return 0;
}