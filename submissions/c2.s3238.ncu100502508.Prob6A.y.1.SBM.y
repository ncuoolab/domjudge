%{
#include <stdio.h>
#include <string.h>
int yylex(void);
void yyerror(const char *message);
%}
%union{
int ival;
}
%token<ival> INUMBER
%type<ival> expr
%left '+''-'
%left '*''%'
%left '@''#'
%%

line 	:expr 	{printf("%d\n",$1);}
	;
expr	:expr expr '+'	{$$=$2+$1;}
	|expr expr '-' 	{$$=$2-$1;}
        |expr expr '*'  {$$=$2*$1;}
        |expr expr '%'  {$$=$2%$1;}
	|expr '@'	{$$=$1+1;}
	|expr '#'	{$$=$1-1;}
	|INUMBER	{$$=$1;}
	;

%%
void yyerror(const char *message)
{
	fprintf(stderr, "%s\n",message);
}

int main(int argc, char *argv[])
{
    yyparse();
    return(0);
}


