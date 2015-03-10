%{
#include <stdio.h>
#include <string.h>
int yylex(void);
void yyerror(const char *message);
%}
%union{
float ival;
}
%token<ival> FNUMBER
%type<ival> expr
%left '+''-'
%left '*''/'
%left '('')'
%nonassoc MINUS
%left '.'
%%

line 	:expr 	{printf("%.1f\n",$1);}
	;
expr	:expr '+' expr	{$$=$1+$3;}
	|expr '-' expr  {$$=$1-$3;}
        |expr '*' expr  {$$=$1*$3;}
        |expr '/' expr  {$$=$1/$3;}
	|expr '.' expr  {$$=$1+$3*0.1;}
	|'('expr')'	{$$=$2;}
	|'-'expr	%prec MINUS	{$$=-1*$2;}
	|FNUMBER	{$$=$1;}
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

