%{
#include <stdio.h>
#include <string.h>
void yyerror(const char *message);
int flag=0;
%}
%union {
double result;
double dval;
}
%token <dval> RNUMBER
%type <dval> expr
%left '/'
%left '*'
%left '+'
%left '-'

%%
line    : expr                  { result = $1; }
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
			printf("%.1lf\n",result);
		}
        return(0);
}

