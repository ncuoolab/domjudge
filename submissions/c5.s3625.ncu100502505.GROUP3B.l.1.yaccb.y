%{

#include <stdio.h>
#include <string.h>
int yylex(void);
void yyerror(const char *message);
int flag = 0;
double  result = 0; 

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
line    : expr    {result = $1;}
        ;
expr  :   expr expr '+'         { $$ = $1 + $2; }
        | expr expr '-'         { $$ = $1 - $2; }
        | expr expr '*'         { $$ = $1 * $2; }
        | expr expr '/'         { $$ = $1 / $2; }
        | RNUMBER
        ;


%%

void yyerror (const char *message) {
        flag = 1;
        fprintf (stderr, "%s\n", "Wrong Formula");
}

int main(int argc, char *argv[]) {
        yyparse();
        if(flag == 0)
	{printf("%.1f\n", result);}
        return 0;
}

