%{

#include <stdio.h>
#include <string.h>
int yylex(void);
void yyerror(const char *message);
int flag = 0,first=0;
double result;
%}
%union {
        double rval;
}

%token <rval> RNUMBER
%type <rval> expr line
%type <rval> node
%left '+' '-'
%left '*' '/'

%%

line    : expr                  { result = $1; flag = 1;}
	;
expr    : expr '+' expr         { $$ = $1 + $3; printf("+ %0.f %0.f ",$1,$3);}
		| expr '-' expr         { $$ = $1 - $3; printf("- %0.f %0.f ",$1,$3);}
        | expr '*' expr         { $$ = $1 * $3; printf("* %0.f %0.f ",$1,$3);}
        | expr '/' expr         { $$ = $1 / $3; printf("/ %0.f %0.f ",$1,$3);}
        | '(' expr ')'          { $$ = $2; /*printf("%.0f ", $2);*/}
		| node					{ /*printf("%.0f ", $2);*/ }
        ;
node	: RNUMBER				{ /*if(first==0) printf("the preorder expression is : "); printf("%.0f " , $1); first=1;*/}

%%

void yyerror (const char *message) {
	fprintf (stderr, "%s\n", message);
}

int main(int argc, char *argv[]) {
        yyparse();
		
		if(flag == 1){
			printf("\nthe result is : %.0f\n",result);
		}
        return 0;
}
