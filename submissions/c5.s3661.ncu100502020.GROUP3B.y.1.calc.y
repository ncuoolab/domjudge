%{

#include <stdio.h>
#include <string.h>
int yylex(void);
void yyerror(const char *message);
double temp = 0;
int flag = 0;
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

line    : expr                  { temp = $1; }
	;
expr    : expr expr '+'     { $$ = $1 + $2; }
	| expr expr '-'        { $$ = $1 - $2; }
        | expr expr '*'        { $$ = $1 * $2; }
        | expr expr '/'        { $$ = $1 / $2; }
        | RNUMBER
        ;

%%

void yyerror (const char *message) {
	printf("Wrong Formula.\n");
	flag = 1;
}

int main(int argc, char *argv[]) {
        yyparse();
		if(flag == 0){
			print("%.1f\n", temp);
		}
        return 0;
}
