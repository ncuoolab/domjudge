%{
#include <stdio.h>
#include <string.h>
int yylex(void);
void yyerror(const char *message);
int vaild=0;
int result;
%}
%union{
int rval;
}

%token<rval>INUMBER
%type<rval> expr
%left '+' '-'
%left '*' '/'

%%
line : expr {result=$1;}
     ;
expr : expr 'i' {$$=$1+1;}
	 | expr 'd' {$$=$1-1;}
	 | expr expr '+' {$$=$2+$1;}
     | expr expr '-' {$$=$2-$1;}
     | expr expr '*' {$$=$2*$1;}
     | expr expr '%' {$$=$2%$1;}
	 | INUMBER
	 ;
%%

void yyerror(const char *message){
     vaild=1;
     printf("Invalid format");
}
int main(int argc, char *argv[]){
    yyparse();
	if(vaild!=1){
		printf(result);
	}
	return 0;
}