%{
#include <stdio.h>
#include <string.h>
#include <math.h>
void yyerror(const char *message);
%}
%union {
double ival;
char *word;
}
%token<ival> INUMBER
%token<word> WORD
%type<ival> expr
%left '+' '-'
%right '^'


%%
line : expr		{printf("%.31f\n",$1);}

expr : expr '+' expr	{$$ = $1 + $3;} 
     | expr '-' expr	{$$ = $1 - $3;}
     | '(' expr ')'	{$$ = $2;}
     | expr '^' INUMBER	{$$ = pow($1,$3);}
     | expr '^' '{' expr '}' {$$ = pow($1,$4);}
     | WORD '{' expr '}' '{' expr '}' {$$ = $3/$6;}
     | INUMBER
%%

void yyerror(const char *message) {
	fprintf(stderr, "%s\n",message);
}

int main(int argc, char *argv[]) {
    yyparse();
    return(0);
}
