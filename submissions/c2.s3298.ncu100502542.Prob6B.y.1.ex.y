%{
#include <stdio.h>
#include <math.h>
#include <string.h>
void yyerror(const char *message);
%}
%union{
	float	ival;
	char* word;
}
%token <ival> DNUMBER
%token <word> WORD
%type<ival> frac
%type<ival> expo
%type<ival> expr
%left '+' '-'
%left '^'
%%
line :	expr	{printf("%.3lf\n",$1);}
	;
expr : expr '+' expr	{$$ = $1 + $3; }
	|	expr '-' expr	{$$ = $1 - $3; }
	|	'(' expr ')'	{$$=$2;}	
	|	frac
	|	expo
	|	DNUMBER			{$$=$1;}	
	;

expo  : expr '^' '{' expr '}'	{$$=pow($1,$4)
;}
	|	'{'	expr '^' expr '}'	{$$=pow($2,$4);}
	|	DNUMBER '^' DNUMBER	{$$=pow($1,$3);}
	;
frac : WORD '{' expr '}' '{' expr '}' {$$=$3/$6;}
	;
%%
void yyerror(const char *message)
{
	fprintf(stderr,"Invalid format\n");
}

int main(int argc, char *argv[]){
	yyparse();
	return(0);
}
