%{
#include <string.h>
#include <stdio.h>
void yyerror(const char *message);
int val=0;
int check=0;
%}
%union{
	int	ival;
	char* word;
}
%token <ival> INUMBER
%type<ival> expr
%%
line : expr	{val=$1;}
	;
expr :	expr expr	'-'	{$$=$2-$1;}
	|	expr expr	'+'	{$$=$2+$1;}
	|	expr expr 	'*'	{$$=$2*$1;}
	|	expr expr 	'%'	{$$=$2%$1;}
	|	expr	'i'	{$$=$1+1;}
	|	expr	'd'	{$$=$1-1;}
	|	INUMBER		{$$=$1;}
	;
%%
void yyerror(const char *message)
{
	check=-1;
	//fprintf(stderr,"Invalid format\n");
}

int main(int argc, char *argv[]){
	yyparse();
	if(check==0)
	printf("%d\n",val);
	else
	printf("Invalid format\n");
	return(0);
}
