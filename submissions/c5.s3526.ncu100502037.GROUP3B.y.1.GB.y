%{

#include <stdio.h>
#include <string.h>
int yylex(void);
void yyerror(const char *message);
double  sum;
int b = 0;

%}
%union {
        double rval;
}

%token <rval> RNUMBER
%type <rval> expr
%left '+' '-'
%left '*' '/'
%right UMINUS

%%

line    : expr                  { sum = $1;   }
	;
expr    : expr expr '+'         { $$ = $1 + $2; }
	| expr expr '-'         { $$ = $1 - $2; }
        | expr expr '*'         { $$ = $1 * $2; }
        | expr expr '/'         { $$ = $1 / $2; }
        | '(' expr ')'          { $$ = $2; }
        | '-' expr %prec UMINUS { $$ = -$2; }
        | RNUMBER  {$$ = $1;}
        ;

%%

void yyerror (const char *message) {
	printf ("Wrong Formula\n");
	b = 1;
}

int main(int argc, char *argv[]) {
        yyparse();

	if(b ==0){
		printf("%.1f\n", sum);
	}
        return 0;
}
