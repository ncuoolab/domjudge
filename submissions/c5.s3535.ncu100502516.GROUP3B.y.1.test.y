%{
#include <stdio.h>
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
expr	:	expr ' ' expr ' ' '+'	{$$ = $1 + $3;}
	|	expr ' ' expr ' ' '-'	{$$ = $1 - $3;}
	|	expr ' ' expr ' ' '*'	{$$ = $1 * $3;}
	|	expr ' ' expr ' ' '/'	{$$ = $1 / $3;}
	|	RNUM
	;
%%
void yyerror (const char *message)
{
        errF = 1;
        printf ("Wrong Formula.\n");
}

int main(int argc, char *argv[])
{
        yyparse();
        if(errF != 1 && num != 0)
                printf("%.1f\n", num);
		else if(errF != 1 && num == 0)
				printf("0\n", num);
        return(0);
}
