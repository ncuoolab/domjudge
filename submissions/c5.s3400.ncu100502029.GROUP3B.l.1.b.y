%{
#include <stdio.h>
#include <string.h>
void yyerror(const char *message);
%}
%union{
double rval;
}
%token <rval> RNUMBER
%type <rval> expr
%left '+' '-'
%left '*' '/'
%%
start	: expr			{printf("%.1f\n",$1);}
	;
expr	: expr expr '+'		{$$=$1+$2;}
	| expr expr '-'		{$$=$1-$2;}
	| expr expr '*'		{$$=$1*$2;}
	| expr expr '/'		{$$=$1/$2;}
	| RNUMBER
	;
%%
void yyerror(const char *message)
{
	printf("Wrong Formula\n");
}

int main(int argc, char *argv[])
{
	yyparse();
	return 0;
}
