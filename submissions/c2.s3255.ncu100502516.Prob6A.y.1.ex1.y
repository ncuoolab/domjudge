%{
#include <stdio.h>
#include <string.h>
void yyerror(const char *message);
int errF = 0;
int num;
%}
%union {
int ival;
char* word;
}
%token <ival> INUMBER
%token <word> ADD
%token <word> SUB
%token <word> MUL
%token <word> MOD
%token <word> INC
%token <word> DEC
%token <word> LOAD
%type <ival> expr
%type <ival> data
%type <word> add
%type <word> sub
%type <word> mul
%type <word> mod
%type <word> inc
%type <word> dec
%type <word> load
%%
line    : expr	{ num = $1; }
        ;
expr    : expr expr add	{$$ = $2 + $1;}
	| expr expr sub	{$$ = $2 - $1;}
	| expr expr mul	{$$ = $2 * $1;}
	| expr expr mod	{$$ = $2 % $1;}
	| expr inc	{$$ = $1 + 1;}
	| expr dec	{$$ = $1 - 1;}
	| load data	{$$ = $2;}
        | INUMBER
        ;
add	: ADD
	;
sub	: SUB
	;
mul	: MUL
	;
mod	: MOD
	;
inc	: INC
	;
dec	: DEC
	;
load	: LOAD
	;
data	: INUMBER
	;
%%
void yyerror (const char *message)
{
		errF = 1;
        printf ("Invalid format\n");
}

int main(int argc, char *argv[]) {
        yyparse();
		if(errF != 1)
			printf("%d\n", num);
        return(0);
}

