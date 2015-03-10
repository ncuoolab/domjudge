%{
#include <stdio.h>
#include <string.h>
void yyerror(const char *message);
int check=0;
double temp;
%}
%union {
        double rval;
	char* cval;
}

%token <rval> RNUMBER
%type <rval> expr
%token <cval> space
%left '+' '-'
%left '*' '/'
%right UMINUS

%%

line    : expr                		 {printf("%.1f\n",$1);}
        ;
expr    : expr space expr space '+'         { $$ = $1 + $3; }
        | expr space expr space '-'         { $$ = $1 - $3; }
        | expr space expr space '*'         { $$ = $1 * $3; }
        | expr space expr space '/'         { $$ = $1 / $3; }
        | '-' RNUMBER %prec UMINUS	    {$$ = -$2;}
	| RNUMBER
        ;

%%

void yyerror (const char *message) {
        fprintf (stderr, "%s\n","Wrong Formula");
	check=1;
}

int main(int argc, char *argv[]) {
        yyparse();
	
        return 0;
}


