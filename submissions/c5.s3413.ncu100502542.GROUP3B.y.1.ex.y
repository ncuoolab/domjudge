%{
#include<stdio.h>
#include <string.h>
void yyerror(const char *message); 
double val=0; int check=0; 
%} 
%union{
	double	dval;
}
%token <dval> DNUMBER 
%type<dval> expr 
%% line : expr	{val=$1;}
	; 
expr :	expr expr  '-'	{$$=$2-$1;}
	|expr expr '+' {$$=$2+$1;} 
	|expr expr '*' {$$=$2*$1;}  
	|expr expr '/' {$$=$2/$1;} 
	| DNUMBER {$$=$1;}
	; 
%% 
void yyerror(const char *message) {
	check=-1;
	fprintf(stderr,"Invalid format\n");
}
int main(int argc, char *argv[]){
	yyparse();
	if(check==0){
	printf("%f\n",val);
	}
	return(0);
}
