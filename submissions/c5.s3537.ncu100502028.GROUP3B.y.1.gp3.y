%{
#include <stdio.h>
#include <string.h>
int yylex(void);
void yyerror(const char *message);
int flag = 0;
float result = 0;
%}
%union {
    float rval;
}

%token <rval> RNUMBER
%type <rval> expr
%left '+' '-' '*' '/'

%%

line    : expr                  { result = $1; }
		;
expr    : expr expr '+'			{ $$ = $1 + $2; }
		| expr expr '-'        	{ $$ = $1 - $2; }
        | expr expr '*'        	{ $$ = $1 * $2; }
        | expr expr '/'        	{ $$ = $1 / $2; }
        | RNUMBER				{ $$ = $1; }
        ;

%%

void yyerror (const char *message) {
	flag = -1;
	printf("Wrong Formula.");
}

int main(int argc, char *argv[]) {
        yyparse();
		if(flag != -1) {
			printf("%.1f\n", result);
		}	
        return 0;
}