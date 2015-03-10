%{
#include <stdio.h>
#include <string.h>
#include <math.h>
int yylex(void);
void yyerror(const char *message);

%}
%union {
        double rval;
        char*WORD;	
}
%token <WORD> word
%token <rval> RNUMBER
%type <rval> expr
%left '+' '-'
%left '^'

%%

line    : expr                  { printf("%.3lf\n", $1); }
	;
expr    : expr '+' expr         { $$ = $1 + $3; }
	| expr '-' expr         { $$ = $1 - $3; }
        | word '{' expr '}' '{' expr '}' { $$ = $3 / $6; }
        | expr '^' '{' expr '}' { $$ = pow($1,$4); }
        | expr '^' RNUMBER      { $$ = pow($1,$3); }
        | '(' expr ')'          { $$ = $2; }
        | RNUMBER
        ;

%%

void yyerror (const char *message) {
	fprintf (stderr, "%s\n", message);
}

int main(int argc, char *argv[]) {
        yyparse();
        return 0;
}

