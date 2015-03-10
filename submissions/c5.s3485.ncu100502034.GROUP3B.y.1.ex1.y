%{
#include <stdio.h>
#include <string.h>
//int yylex(void);
void yyerror(const char *message);
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
line    : expr                  { printf("%.1f\n", $1); }
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
        printf ("Wrong Formula\n");
}

int main(int argc, char *argv[]) {
        yyparse();
        return(0);
}
