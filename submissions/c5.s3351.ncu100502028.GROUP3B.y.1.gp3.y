%{

#include <stdio.h>
#include <string.h>
int yylex(void);
void yyerror(const char *message);

%}
%union {
        double rval;
}

%token <rval> RNUMBER
%type <rval> expr
%left '+' '-'
%left '*' '/'

%%

line    : expr                  { printf("%.1f\n", $1); }
	;
expr    : expr expr '+'			{ $$ = $1 + $3; }
		| expr expr '-'        	{ $$ = $1 - $3; }
        | expr expr '*'        	{ $$ = $1 * $3; }
        | expr expr '/'        	{ $$ = $1 / $3; }
        | '(' expr ')'          { $$ = $2; }
        | RNUMBER
        ;

%%

void yyerror (const char *message) {
	fprintf (stderr, "Wrong Formula\n");
}

int main(int argc, char *argv[]) {
        yyparse();
        return 0;
}