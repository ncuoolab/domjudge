%{
#include <stdio.h>
#include <string.h>
int error = 0, result = 0;
void yyerror(const char *message);
%}
%union{
int num;
char* word;
}
%token <num> NUMBER
%token <word> INC
%token <word> DEC

%type <num> expr
%type <num> expr1
%left '+' '-'
%left '*' '%'
%nonassoc first
%%

s	: expr	{ result = $1; }
	;
expr	: expr  expr '+' { $$ = $2 + $1; }
        | expr  expr '-' { $$ = $2 - $1; }
        | expr  expr '*' { $$ = $2 * $1; }
        | expr  expr '%' { $$ = $2 % $1; }	 
	| expr1
	| NUMBER
	;
expr1	: NUMBER INC	{ $$ = $1 + 1;}
	| NUMBER DEC	{ $$ = $1 - 1;}
	;
%%
void yyerror(const char *message)
{	
	error = 1;
	printf("Invalid format\n");
}
int main(int argc, char *argv[])
{
   	yyparse();
	if(error == 0)
	{
		printf("%d\n", result);
   	}
	
	return(0);
}

