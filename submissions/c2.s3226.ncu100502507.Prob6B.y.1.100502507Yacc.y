%{
#include <stdio.h>
#include <string.h>
#include <math.h>
void yyerror(const char *message);
%}

%union {
	double rval;
	char *word;
}

%token<word> FRAC
%token<rval> REALNUMBER
%type<word> frac
%type<rval> expr
%left '+' '-'
%right '^'

%%

line	: expr	{ printf("%.3f\n", $1); }
	;
expr	: expr '+' expr				{ $$ = $1 + $3; }
	| expr '-' expr				{ $$ = $1 - $3; }
	| expr '^' REALNUMBER			{ $$ = pow($1, $3); }
	| expr '^' '{' expr '}'			{ $$ = pow($1, $4); }
	| '(' expr ')'				{ $$ = $2; }
	| frac '{' expr '}' '{' expr '}'	{ $$ = $3 / $6; }
	| REALNUMBER
	;

frac	: FRAC
	;

%%

void yyerror(const char *message) {
	fprintf(stderr, "%s\n", "Invalid format");
}

int main(int argc, char *argv[]) {
	yyparse();
	return 0;
}
