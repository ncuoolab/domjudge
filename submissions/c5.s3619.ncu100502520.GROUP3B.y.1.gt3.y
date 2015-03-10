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
%left '+' '-' '*' '/'
 
%% 
line : expr {ans = $1; }
     ; 
expr    : expr expr '+' { $$ = $1 + $2; }
	| expr expr '-' { $$ = $1 - $2; }
        | expr expr '*' { $$ = $1 * $2; } 
        | expr expr '/' { $$ = $1 / $2; }  
        | RNUMBER
        ; 
%% 

void yyerror (const char *message) {
        flag = 1;
	printf ("Wrong Formula.");
}

int main(int argc, char *argv[]) {
        yyparse();
	if(flag ==0){
		printf("%.1f\n", ans);
	}
        return 0;
}
