%{
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
int yylex(void);
void yyerror(const char *message);
string str[1000];
int ptr = 0;

%}
%union {
        int rval;
}

%token <rval> RNUMBER
%type <rval> expr
%left '+' '-'
%left '*' '/'
%right UMINUS

%%

line    : expr                  { printf("\nthe result is : %d\n", $1); }
	;
expr    : expr '+' expr         { $$ = $1 + $3; str[ptr++] = "+";}
	| expr '-' expr         { $$ = $1 - $3; str[ptr++] = "-";}
        | expr '*' expr         { $$ = $1 * $3; str[ptr++] = "*";}
        | expr '/' expr         { $$ = $1 / $3; str[ptr++] = "/";}
        | '(' expr ')'          { $$ = $2; }
        | '-' expr %prec UMINUS { $$ = -$2; }
        | RNUMBER               {str[ptr++] = $$;}
        ;

%%

void yyerror (const char *message) {
	fprintf (stderr, "%s\n", message);
}

int main(int argc, char *argv[]) {
        yyparse();
        for(int i = 0 ; i < ptr ; i++)
            printf(str[i]);
        return 0;
}
