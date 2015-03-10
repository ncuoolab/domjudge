%{
#include <stdio.h>
#include <string.h>
int yylex(void);
void yyerror(const char *message); 
int flag = 0;
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
line : expr { ans = $1; }
        ;
expr : expr expr '+'{ $$ = $1 + $2; }
        | expr expr '-' { $$ = $1 - $2; }
        | expr expr '*' { $$ = $1 * $2; }
        | expr expr '/' { $$ = $1 / $2; }
        | RNUMBER
        ;
%%
void yyerror (const char *message) {
	printf("Wrong Formula.\n");
	flag = 1;
}
int main(int argc, char *argv[]) {        
	yyparse();
	if(flag == 0)	
	{printf("%.1f\n", ans);}
	return 0;
}

