%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int yylex(void);
void yyerror(const char *message);
float output = 0;
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

line    : expr                  { output = $1;}//printf("%.1f\n", $1); }
        ;
expr    : expr expr '+'        { $$ = $1 + $2; }
        | expr expr '-'        { $$ = $1 - $2; }
        | expr expr '*'        { $$ = $1 * $2; }
        | expr expr '/'        { $$ = $1 / $2; }
        | RNUMBER
        ;

%%

void yyerror(const char *message) {
        printf ("Wrong Formula.\n");
        exit(0);
        fprintf (stderr, "%s\n", message);

}

int main(int argc, char *argv[]) {
        yyparse();
        printf("%.1f",output);
        return 0;
}
