%{
#include <stdio.h>
#include <string.h>
void yyerror(const char *message);
%}
%union {
double dval;
}
%token <dval> RNUMBER
%type <dval> expr
%left '/'
%left '*'
%left '+'
%left '-'

%%
line    : expr                  { printf("%f\n", $1); }
        | expr '+'		{ yyerror("Wrong Formula");}
	| expr '-'              { yyerror("Wrong Formula");}
	| expr '*'              { yyerror("Wrong Formula");}
	| expr '/'              { yyerror("Wrong Formula");}
	 ;
expr    : expr expr '+'         { $$ = $1 + $2; }
        | expr expr '-'		{ $$ = $1 - $2; }
	| expr expr '*'         { $$ = $1 * $2; }
	| expr expr '/'         { $$ = $1 / $2; }
	| RNUMBER
        ;
%%
void yyerror (const char *message)
{
        fprintf (stderr, "%s\n",message);
}

int main(int argc, char *argv[]) {
        yyparse();
        return(0);
}

