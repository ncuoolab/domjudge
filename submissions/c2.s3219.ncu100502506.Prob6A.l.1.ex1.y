%{
#include <stdio.h>
#include <string.h>
#include <math.h>
void yyerror(const char *message);
%}
%union {
float rval;
char *word;
}
%token <rval> RNUMBER
%token <word> WORD
%type <rval> expr
%type <word> test
%left '+'
%left '-'
%right '^'
%left '('')'
%nonassoc POW
%%
line    : expr        		{ printf("%.3lf", $1); }		
	;
expr    : expr '+' expr         { $$ = $1 + $3; }
        | expr '-' expr		{ $$ = $1 - $3; }
	| expr'^''{'expr'}'	{ $$ = pow( $1,$4);}
	| '('expr ')'           { $$ = $2;}
	| test'{'expr'}''{'expr'}'{ $$=$3/$6;}
	| RNUMBER 
        ;
test	: WORD		
	;
%%
void yyerror (const char *message)
{
        fprintf (stderr, "%s\n","Invalid format");
}

int main(int argc, char *argv[]) {
        yyparse();
        return(0);
}

