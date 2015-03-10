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
	| expr  INC	{$$ = $1 + 1;}
	| expr  DEC     {$$ = $1 - 1;}
	| NUMBER
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

