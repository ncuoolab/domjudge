%{

#include <stdio.h>
#include <string.h>
int yylex(void);
void yyerror(const char *message);
int check = 0;
double ans;

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

line    : expr                  { ans = $1; }
		;
expr    : expr expr '+'         { $$ = $1 + $2; }
		| expr expr '-'         { $$ = $1 - $2; }
        | expr expr '*'         { $$ = $1 * $2; }
        | expr expr '/'         { $$ = $1 / $2; }
        | RNUMBER
        ;

%%

void yyerror (const char *message) {
	check = 1;
	printf ("Wrong Formula.\n");
}

int main(int argc, char *argv[]) {
        yyparse();
		if(check == 0)
			printf("%.1f\n", ans);
        return 0;
}
