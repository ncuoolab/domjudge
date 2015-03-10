%{
#include <stdio.h>
#include <string.h>
int yylex(void);
void yyerror(const char *message);
int vaild=0;
double result=0;
%}
%union{
double rval;
}

%token<rval>RNUMBER
%type<rval> expr
%left '+' '-'
%left '*' '/'
%right UMINUS

%%
line : expr {result=$1;}
     ;
expr : expr expr '+' {$$=$2+$1;}
     | expr expr '-' {$$=$2-$1;}
     | expr expr '*' {$$=$2*$1;}
     | expr expr '/' {$$=$2/$1;}
	 | RNUMBER
	 ;
%%

void yyerror(const char *message){
     vaild=1;
     printf("Wrong Formula.");
}
int main(int argc, char *argv[]){
    yyparse();
	if(vaild!=1){
		printf("%d", result);
	}
	return 0;
}