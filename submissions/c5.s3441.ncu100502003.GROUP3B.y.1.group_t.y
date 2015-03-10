%{
#include <stdio.h>
#include <string.h>
#include <math.h>
void yyerror(const char* msg);
/*double tmp;
int flag=0;*/
%}
%union{
double rval;
}
%token<rval>	NUMBER
%type<rval>	expr

%left '+' '-'
%left '*' '/'

%%

line	: expr		{printf("%.1f\n", $1);}
	;
expr	: expr '@' expr '@' '+'		{$$ = $1+$3;}
	| expr '@' expr '@' '-'		{$$ = $1-$3;}
	| expr '@' expr '@' '*'		{$$ = $1*$3;}
	| expr '@' expr '@' '/'		{$$ = $1/$3;}
	| NUMBER
	;

%%
void yyerror(const char* msg)
{
	/*flag=1;*/
	fprintf(stderr, "%s\n", "Wrong Formula");
}

int main(int argc, char* argv[])
{
	yyparse();
	/*if(flag==0)
	{printf("%.1f\n", tmp);}
	else
	{}*/
	return(0);
}
