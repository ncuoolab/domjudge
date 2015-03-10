%{
#include <stdio.h>
#include <string.h>
int yylex(void);
void yyerror(const char *message);
int flag = 0;
int result = 0;
%}
%union {
int ival;
}
%token <ival> INUMBER
%type <ival> expr
%left '+' '-' '*' '%'
%%
line    : expr                  { result = $1; }
	    ;
expr    : expr 'i'				{ $$ = $1 + 1; }
		: expr 'd'				{ $$ = $1 - 1; }
		: expr expr '+'			{ $$ = $2 + $1; }
		: expr expr '-'        	{ $$ = $2 - $1; }
		: expr expr '*'        	{ $$ = $2 * $1; }
		: expr expr '%'        	{ $$ = $2 % $1; }
        | INUMBER				{ $$ = $1; }
        ;
%%

void yyerror (const char *message)
{
		valid = 1;
        printf("Invalid format");
}

int main(int argc, char *argv[]) {
        yyparse();
		if(valid != 1) {
			printf("%d", result);
		}	
        return(0);
}