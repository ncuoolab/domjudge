%{
#include <stdio.h>
#include <string.h>
void yyerror(const char *message);
double ans;
int flag;
%}
%union {
double rval;
}
%token <rval> RNUMBER
%type <rval> expr

%%
line    : expr                  { ans = $1; flag = 1;}
         ;
expr    : expr expr '+'         { $$ = $1 + $2; }
	| expr expr '-'         { $$ = $1 - $2; }
        | expr expr '*'         { $$ = $1 * $2; }
        | expr expr '/'         { $$ = $1 / $2; }
        | RNUMBER
        ;
%%
void yyerror (const char *message)
{
 //       fprintf (stderr, "%s\n",message);
	flag = 0;
}

int main(int argc, char *argv[]) {
        yyparse();
	if(flag==1) {
		printf("%.1f\n", ans);
	}
	else {
		printf("Wrong Formula.");
	}
        return(0);
}

