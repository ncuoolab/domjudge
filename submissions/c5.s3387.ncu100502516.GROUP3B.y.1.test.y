%{
#include <stdio.h>
#include <math.h>
void yyerror(const char *message);
int errF = 0;
double num;
%}
%union
{
double rval;
}
%token <rval> RNUM
%left '+' '-'
%left '*' '/'
%type <rval> expr
%%
line	:	expr	{num = $1;}
	;
expr	:	expr expr '+'	{$$ = $1 + $2;}
	|	expr expr '-'	{$$ = $1 - $2;}
	|	expr expr '*'	{$$ = $1 * $2;}
	|	expr expr '/'	{$$ = $1 / $2;}
	|	RNUM
	;
%%
void yyerror (const char *message)
{
        errF = 1;
        printf ("Wrong Fomula\n");
}

int main(int argc, char *argv[])
{
        yyparse();
        if(errF != 1)
                printf("%.1f\n", num);
        return(0);
}

