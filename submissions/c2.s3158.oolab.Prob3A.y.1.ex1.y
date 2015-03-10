%{
#include <stdio.h>
#include <string.h>
//int yylex(void);
void yyerror(const char *message);
%}
%union {
int ival;
}
%token <ival> INUMBER
%type <ival> expr
%left '+'
%%
line    : expr                  { printf("%d\n", $1); }
	                ;
expr    : expr '+' expr         { $$ = $1 + $3; }
        | INUMBER	{$$=$1;}
        ;
%%

void yyerror (const char *message)
{
        fprintf (stderr, "%s\n",message);
}

int main(int argc, char *argv[]) {
        yyparse();
        return 0;
}
