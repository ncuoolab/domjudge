%{
#include <stdio.h>
#include <string.h>
void yyerror(const char *message);
double result;
int flag=0;
%}
%union{
double rval;
}
%token <rval> RNUMBER
%type <rval> expr
%left '+' '-'
%left '*' '/'
%%
start	: expr			{result=$1;}
	;
expr	: expr expr '+'		{$$=$1+$2;}
	| expr expr '-'		{$$=$1-$2;}
	| expr expr '*'		{$$=$1*$2;}
	| expr expr '/'		{$$=$1/$2;}
	| RNUMBER
	;
%%
void yyerror(const char *message)
{
	flag = 1;
}

int main(int argc, char *argv[])
{
	yyparse();
	if(flag == 0)
	{
		printf("%.1f\n",result);
	}
	else
	{
		 printf("Wrong Formula\n");
	}
	return 0;
}
