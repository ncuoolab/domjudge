%{
#include <stdio.h>
#include <string.h>

int yylex(void);
int flag = 0;
double result = 0.0;
char* er = "Wrong Formula";

int yyerror(const char *message);
%}

%union {
        double rval;
}

%token <rval> RNUMBER 
%type <rval> expr 

%% line : expr 				{ result =  $1;  }
; 
expr    : expr  expr  '+'       	{ $$ = $2 + $1; }
        | expr  expr  '-'       	{ $$ = $1 - $2; }
        | expr  expr  '*'      	 	{ $$ = $2 * $1; }
        | expr  expr  '/'       	{ $$ = $1 / $2; }
	| RNUMBER               	{ $$ = $1;      }
;

%% int yyerror (const char *message) {
        flag=1;
        printf ("%s\n" , er);
        return 0;
}

int main(int argc, char *argv[]) {
        yyparse();

        if (flag==0){
                printf("%.1f\n", result);
        }

        return 0;
}
