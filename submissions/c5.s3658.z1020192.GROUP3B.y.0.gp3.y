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

line    : expr                  { printf("%.1f\n", $1); }
        ;
expr    : expr expr '+'        { $$ = $1 + $2; }
        | expr expr '-'        { $$ = $1 - $2; }
        | expr expr '*'        { $$ = $1 * $2; }
        | expr expr '/'        { $$ = $1 / $2; }
        | RNUMBER
        ;

%%

void yyerror (const char *message) {
        printf ("Wrong Formula\n");
        fprintf (stderr, "%s\n", message);
}

int main(int argc, char *argv[]) {
        yyparse();
        return 0;
}
