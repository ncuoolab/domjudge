%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int yylex(void);
void yyerror(const char *message);

%}
%union {
        int rval;
}

%token <rval> RNUMBER
%type <rval> expr
%left '+' '-'
%left '*' '/'
%right UMINUS

%%

line    : expr                  { printf("\nthe result is : %d\n", $1); }
	;
expr    : expr '+' expr         { $$ = $1 + $3; printf("+ ");}
	| expr '-' expr         { $$ = $1 - $3; printf("- ");}
        | expr '*' expr         { $$ = $1 * $3; printf("* ");}
        | expr '/' expr         { $$ = $1 / $3; printf("/ ");}
        | '(' expr ')'          { $$ = $2; }
        | '-' expr %prec UMINUS { $$ = -$2; printf(" -");}
        | RNUMBER               {printf("%d ",$$);}
        ;

%%

void yyerror (const char *message) {
	fprintf (stderr, "%s\n", message);
}

int main(int argc, char *argv[]) {
        yyparse();
        return 0;
}
