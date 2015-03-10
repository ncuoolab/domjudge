%{
#include <stdio.h>
#include <string.h>
int yylex(void);
void yyerror(const char *message);
int vaild=0;
int result=0;
%}
%union {
double rval;
}

%token <rval> RNUMBER
%type <rval> expr
%left '+' '-'
%left '*' '/'

%%
line : expr {result=$1;}
     ;
expr : expr '+' expr {$$=$1+$3;}
     | expr '-' expr {$$=$1-$3;}
     | expr '*' expr {$$=$1*$3;}
     | expr '/' expr {$$=$1/$3;}
	 | '(' expr ')'  {$$ = $2; }
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
		printf("%.1f", result);
	}
	return 0;
}