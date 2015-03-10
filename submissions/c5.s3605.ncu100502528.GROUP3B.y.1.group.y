%{

#include <stdio.h>
#include <string.h>

int error=1;
double result=0;
int yylex(void);
void value(double);
void yyerror(const char *message);

%}
%union {
        double rval;
}

%token <rval> RNUMBER
%type <rval> expr
%%

line    : expr                  {value($1);}
	;
expr    : expr expr '+'         { $$ = $1 + $2; }
	| expr expr '-'         { $$ = $1 - $2; }
        | expr expr '*'         { $$ = $1 * $2; }
        | expr expr '/'         { $$ = $1 / $2; }
        | RNUMBER
        ;

%%


void  yyerror (const char *message) {
	printf("Wrong Formula.\n");
	error=0;
}
void value(double a)
{
 result=a;
}


int main(int argc, char *argv[]) {
        yyparse();
	if(error==1)
	{
	 printf("%.1f",result);
	}
        return 0;
}

