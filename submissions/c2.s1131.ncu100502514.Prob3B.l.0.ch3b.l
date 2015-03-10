%{
#include <string.h>
#define bool int
#define true 1
#define false 0

bool favorites[1000] = {false};
char line[1000] = "";
int favoritesPtr = 0;
bool isFirstLine = true, isFavSet = false;
%}
word            [a-zA-Z0-9]+
newline         "\n"
separator       .
%%
{word} {
    if(isFirstLine){
		if(strcmp(yytext, "Favorite")==0){
			favorites[favoritesPtr++] = true;
		}else{
			favorites[favoritesPtr++] = false;
		}
	}else{
		strcat(line, yytext);
		if(favorites[favoritesPtr++] && strcmp(yytext, "noodles")==0){
			isFavSet = true;
		}
	}
}
{newline} {
	if(!isFirstLine){
		if(isFavSet){
			printf("%s\n", line);
		}
		strcpy(line, "");
	}
	favoritesPtr = 0;
	isFirstLine = false;
	isFavSet = false;
}
{separator} {
	if(!isFirstLine){
		strcat(line, yytext);
	}
}
%%
int main(int argc, char *argv[]) {
	yylex();
    return 0;
}