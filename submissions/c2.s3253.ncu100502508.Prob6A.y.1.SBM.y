%{
#include <stdio.h>
#include <string.h>
int yylex(void);
void yyerror(const char *message);
int error=0;
int result;
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

line 	:expr 	{result=$1;}
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
	error=1;
	printf("Invalid format\n");
}

int main(int argc, char *argv[])
{
    yyparse();
    if(error!=1)
{
	printf("%d\n",result);
}
    return(0);
}


