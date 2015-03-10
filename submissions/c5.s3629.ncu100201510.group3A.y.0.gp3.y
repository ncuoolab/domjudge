%{

#include <stdio.h>
#include <string.h>
int yylex(void);
void yyerror(const char *message);
char str[1000];

%}
%union {
        double rval;
}

%token <rval> RNUMBER
%type <rval> expr
%left '+' '-'
%left '*' '/'
%right UMINUS

%%

line    : expr                  { printf("\nthe result is : %.0f\n", $1); }
	;
expr    : expr '+' expr         { $$ = $1 + $3; }
	| expr '-' expr         { $$ = $1 - $3; }
        | expr '*' expr         { $$ = $1 * $3; }
        | expr '/' expr         { $$ = $1 / $3; }
        | '(' expr ')'          { $$ = $2; }
        | '-' expr %prec UMINUS { $$ = -$2; }
        | RNUMBER               {printf($1);}
        ;

%%

void yyerror (const char *message) {
	fprintf (stderr, "%s\n", message);
}

int main(int argc, char *argv[]) {
        yyparse();
        return 0;
}
