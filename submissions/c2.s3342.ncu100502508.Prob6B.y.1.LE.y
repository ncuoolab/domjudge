%{
#include <stdio.h>
#include <string.h>
#include <math.h>
int yylex(void);
void yyerror(const char *message);
int error=0;
double result;
%}
%union{
double ival;
}
%token<ival> DNUMBER
%type<ival> expr
%left '+''-'
%left '*''@'
%left '^'
%left '('')'
%%

line 	:expr 	{result=$1;}
	;
expr	:expr '+' expr  {$$=$1+$3;}
	|expr '-' expr  {$$=$1-$3;}
        |expr '*' expr  {$$=$1*$3;}
	|'(' expr ')'	{$$=$2;}
	|expr '^' expr 	{$$=pow($1,$3);}
	|expr '^' '{' expr '}' {$$=pow($1,$4);}
	| '@' '{' expr '}' '{' expr '}'	{$$=$3/$6;}
	|DNUMBER	{$$=$1;}
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
		printf("%.3f\n",result);
	}
    return(0);
}


