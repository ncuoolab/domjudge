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
		| expr 'd'				{ $$ = $1 - 1; }
		| expr expr '+'			{ $$ = $2 + $1; }
		| expr expr '-'        	{ $$ = $2 - $1; }
		| expr expr '*'        	{ $$ = $2 * $1; }
		| expr expr '%'        	{ $$ = $2 % $1; }
        | INUMBER				{ $$ = $1; }
        ;
%%

void yyerror (const char *message)
{
		flag = 1;
        
}

int main(int argc, char *argv[]) {
        yyparse();
		if(flag != 1) {
			printf("%d", result);
		}
		else{
			printf("Invalid format");
		}
        return(0);
}