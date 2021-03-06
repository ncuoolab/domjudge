%{

#include <stdio.h>
#include <string.h>
int yylex(void);
void yyerror(const char *message);

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

line    : expr                  { printf("the result is : %.0f\n", $1); }
	;
expr    : expr '+' expr         { $$ = $1 + $3; printf($2);}
	| expr '-' expr         { $$ = $1 - $3; printf($2);}
        | expr '*' expr         { $$ = $1 * $3; printf($2);}
        | expr '/' expr         { $$ = $1 / $3; printf($2);}
        | '(' expr ')'          { $$ = $2; printf($1);printf($3);}
        | '-' expr %prec UMINUS { $$ = -$2; }
        | RNUMBER
        ;

%%

void yyerror (const char *message) {
	fprintf (stderr, "%s\n", message);
}

int main(int argc, char *argv[]) {
        yyparse();
        return 0;
}
