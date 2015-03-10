%{
#include <stdio.h>
#include <string.h>
#include <math.h>
void yyerror(const char* msg);
int answer;
int flag=0;
%}

%union{
int ival;
}

%token<ival>	INUMBER
%type<ival>	expr
%left '+' '-'
%left '*' '%'
%left '>' '<'

%%
line	: expr		{answer=$1;}
	;
expr	: expr expr '+'	{$$ = $2+$1;}
	| expr expr '-' {$$ = $2-$1;}
	| expr expr '*'	{$$ = $2*$1;}
	| expr expr '%' {$$ = $2%$1;}
	| expr '>'	{$$ = $1+1;}
	| expr '<'	{$$ = $1-1;}
	| INUMBER
	;
%%
void yyerror(const char*message) {
	printf("Invalid format\n");
	flag = 1;
}

int main(int argc, char* argv[]){
	yyparse();
	if(flag == 0)
	 {printf("%d\n", answer);}
	else
	{}
	return 0;
}
