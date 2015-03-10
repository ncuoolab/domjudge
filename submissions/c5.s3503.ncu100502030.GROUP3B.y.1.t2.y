%{
#include <stdio.h>
#include <string.h>
int yylex(void);
int isErr = 0;
double result;
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

line    : expr                  { result = $1; }
	;
expr    : expr  expr '+'        { $$ = $1 + $2; }
	| expr  expr '-'        { $$ = $1 - $2; }
        | expr  expr '*'        { $$ = $1 * $2; }
        | expr  expr '/'        { $$ = $1 / $2; }
        | RNUMBER
        ;

%%

void yyerror (const char *message) {
	isErr = 1;
	fprintf (stderr, "%s\n", "Wrong Formula.");
}

int main(int argc, char *argv[]) {
        yyparse();
	if(isErr!=1)
		printf("%0.1f\n",result); 
        return 0;
}


