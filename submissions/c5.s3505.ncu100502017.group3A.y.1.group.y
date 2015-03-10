%{

#include <stdio.h>
#include <string.h>
char* result;
int yylex(void);
void yyerror(const char *message);

%}
%union {
        char* word;
}

%token <word> NUM
%type <word> expr
%left '+' '-'
%left '*' '/'

%%

line    : expr                  { result=$1; }
	;
expr    : expr '+' expr         { $$ = '+' + $1 +' '; }
		| expr '-' expr         { $$ = '-' + $1 +' ' ;}
        | expr '*' expr         { $$ = '*' + $1 +' '; }
        | expr '/' expr         { $$ = '/' + $1 +' ';}
        | '(' expr ')'          { $$ = $2; }
        | NUM
        ;

%%

void yyerror (const char *message) {
	fprintf (stderr, "%s\n", message);
}

int main(int argc, char *argv[]) {
        yyparse();
        return 0;
}