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
expr :	expr expr  '-'	{$$=$1-$2;}
	|expr expr '+' {$$=$1+$2;} 
	|expr expr '*' {$$=$1*$2;}  
	|expr expr '/' {$$=$1/$2;} 
	| DNUMBER {$$=$1;}
	; 
%% 
void yyerror(const char *message) {
	check=-1;
	//fprintf(stderr,"Wrong Formula\n");
}
int main(int argc, char *argv[]){
	yyparse();
	if(check==0)
	printf("%.1f\n",val);
	else
	printf("%s\n","Wrong Formulat");
	return(0);
}
