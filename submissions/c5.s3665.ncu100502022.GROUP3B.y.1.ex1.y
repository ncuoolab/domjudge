%{
#include "global.h"
#include <stdio.h>
#include <string.h>
void yyerror(const char *message);
%}
%union {
int flag  = 0;
double dval;
}
%token RNUMBER
%left '/'
%left '*'
%left '+'
%left '-'

%%
line    : expr                  { dval = $1; }
        |
		;
expr    : expr expr '+'         { $$ = $1 + $2; }
        | expr expr '-'			{ $$ = $1 - $2; }
		| expr expr '*'         { $$ = $1 * $2; }
		| expr expr '/'         { $$ = $1 / $2; }
		| RNUMBER
        ;
%%
void yyerror (const char *message)
{
        flag = 1;
}

int main(int argc, char *argv[]) {
        yyparse();
		if(flag == 1){
			printf("Wrong Formula.");
		}
		else{
			printf("%.1lf\n",dval);
		}
        return(0);
}

