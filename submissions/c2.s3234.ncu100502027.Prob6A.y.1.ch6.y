%{
#include <stdio.h>
#include <string.h>
int yylex(void);
void yyerror(const char *message);
%}
%union{
int rval;
}

%token<rval>INUMBER
%type<rval> expr
%left '+' '-'
%left '*' '/'

%%
line : expr {printf("%d\n",$1);}
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
     printf("Invalid format");
}
int main(int argc, char *argv[]){
    yyparse();
	return 0;
}