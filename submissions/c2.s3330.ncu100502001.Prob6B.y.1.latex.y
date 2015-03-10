%{
#include<stdio.h>
#include<string.h>
#include<math.h>
void yyerror(const char *message);
%}
%union{
double rval;
char *word;
}
%token<rval> RNUMBER
%token<word> FRAC
%type<rval> expr
%left '+''-'
%right '^'
%nonassoc '('')'
%nonassoc '\\''{''}''\n'
%%
start : expr '\n' 	{printf("%.3lf\n",$1);return(0);}
;
expr : expr '+' expr	{$$=$1+$3;}
     | expr '-' expr	{$$=$1-$3;}
     | '(' expr ')'	{$$=$2;}
     | '\\'FRAC '{' expr '}' '{' expr '}'	{$$=$4/$7;}	 
     | expr '^' RNUMBER	{$$=pow($1,$3);}
     | expr '^' '{' expr '}'	{$$=pow($1,$4);}	
     | RNUMBER	{$$=$1;}
;
%%
void yyerror(const char *message){
	printf("Invalid format\n");
}
int main(int argc, char *argv[]){
	yyparse();
	return(0);
}

