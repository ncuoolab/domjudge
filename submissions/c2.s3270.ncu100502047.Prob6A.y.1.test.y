%{
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
void yyerror(const char *message);
int i = 0;
int sum = 0;
%}
%union{
	int ival;
}
%type<ival> expr
%token<ival> ADD
%token<ival> SUB
%token<ival> MUL
%token<ival> MOD
%token<ival> INC
%token<ival> DEC
%token<ival> NUMBER
%%
line : expr	{sum = $1;}
     ;
expr : expr expr ADD 	{$$ = $2 + $1;}
     | expr expr SUB 	{$$ = $2 - $1;}
     | expr expr MUL	{$$ = $2 * $1;}
     | expr expr MOD 	{$$ = $2 % $1;}
     | expr INC 	{$$ = $1++;}
     | expr DEC 	{$$ = $1--;}
     | NUMBER	{$$ = $1;}
     ;

%%
void yyerror(const char *message){
	i = 1;
	printf("Invalid format");
}
int main(int argc, char *argv[]){
	yyparse();
	if(i == 0){
		printf("%d",sum);
	}
	return 0;
}

