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
%type <rval> test
%left '+' '-'
%left '*' '/'
%right UMINUS

%%
line    : test    { printf("%.1f\n", $1); }
        ;
expr  : RNUMBER

test :    expr expr '+'         { $$ = $1 + $2; }
        | expr expr '-'         { $$ = $1 - $2; }
        | expr expr '*'         { $$ = $1 * $2; }
        | expr expr '/'         { $$ = $1 / $2; }
        | '(' expr ')'          { $$ = $2; }
        | '-' expr %prec UMINUS { $$ = -$2; }
        ;

%%

void yyerror (const char *message) {
        fprintf (stderr, "%s\n", "Wrong Formula");
}

int main(int argc, char *argv[]) {
        yyparse();
        return 0;
}

