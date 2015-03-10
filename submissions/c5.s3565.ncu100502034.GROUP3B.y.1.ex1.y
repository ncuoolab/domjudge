%{
#include <stdio.h>
#include <string.h>
//int yylex(void);
void yyerror(const char *message);
double result;
int errorr = 0;
%}
%union {
double ival;
}
%token <ival> INUMBER
%type <ival> expr
%left '+'
%left '-'
%left '*'
%left '/'
%%
line    : expr                  {result = $1; }
	                ;
expr    : expr  expr '+'         { $$ = $1 + $2; }
        | expr  expr '-'		{ $$ = $1 - $2; }
	| expr  expr '*'		{ $$ = $1 * $2; }
	| expr  expr '/'		{ $$ = $1 / $2; }
	| INUMBER	{$$=$1;}
        ;
%%

void yyerror (const char *message)
{
	errorr = 1;
        printf ("Wrong Formula\n");
}

int main(int argc, char *argv[]) {
        yyparse();
	if(errorr==0)
		printf("%.1f\n",result);		
        return(0);
}
