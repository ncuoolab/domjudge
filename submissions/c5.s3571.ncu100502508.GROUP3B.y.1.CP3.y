%{
#include <stdio.h>
#include <string.h>
#include <math.h>
int yylex(void);
void yyerror(const char *message);
int flag=0;
double result;
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
	flag=1;
	printf ("Wrong Formula.\n");
}

int main(int argc, char *argv[]) {
        yyparse();
	if(flag!=1)
	{
		if(result==0)
		{
			printf("0\n");
		}
		else
		{
			printf ("%.1f\n",result);
		}
	}
        return 0;
}


