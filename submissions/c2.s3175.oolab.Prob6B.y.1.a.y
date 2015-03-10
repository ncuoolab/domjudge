%{
#include <stdio.h>
#include <math.h>
//#define YYSTYPE double
int yylex();
int isValid;
double ans;
void yyerror(const char* message){
	isValid = 0;
	printf("Invalid format\n");
};
%}
%union{
	double fval;
}
%token<fval> NUMBER
%token FRAC_HEAD
%type<fval> expression
%type<fval> base
%type<fval> term
%left '-' '+'
%%
startsymbol
	: expression {
		ans = $1;
	}
	;

expression
	: expression '+' term
	{
		//printf("rule 11 (%.3lf, %.3lf)\n", $1, $3);
		$$ = $1 + $3;
	}
	| expression '-' term
	{
		//printf("rule 12 (%.3lf, %.3lf)\n", $1, $3);
		$$ = $1 - $3;
	}
	| term
	{
		//printf("rule 13 %.3lf\n", $1);
		//printf("rule 13\n");
		$$ = $1
	}
	;

term
	: base '^' NUMBER
	{
		//printf("rule 21 (%.3lf, %.3lf)\n", $1, $3);
		$$ = pow($1, $3);
	}
	| base '^' '{' expression '}'
	{
		//printf("rule 22 (%.3lf, %.3lf)\n", $1, $4);
		$$ = pow($1, $4);

	}
	| FRAC_HEAD '{' expression '}' '{' expression '}'
	{
		//printf("rule 23 (%.3lf, %.3lf)\n", $3, $6);
		$$ = $3 / $6;
	}
	| NUMBER
	{
		//printf("rule 24 (%.3lf)\n", $1);
		$$ = $1;
	}
	;

base
	: NUMBER
	{
		//printf("rule 31 %.3lf\n", $1);
		$$ = $1;
	}
	| '(' expression ')'
	{
		//printf("rule 32 %.3lf\n", $2);
		$$ = $2;
	}
	| FRAC_HEAD '{' expression '}' '{' expression '}'
	{
		//printf("rule 33 (%.3lf, %.3lf)\n", $3, $6);
		$$ = $3 / $6;
	}
	;
%%

int main()
{
	isValid = 1;
	yyparse();
	if(isValid){
		printf("%.3lf\n", ans);
	}
	return 0;
}
