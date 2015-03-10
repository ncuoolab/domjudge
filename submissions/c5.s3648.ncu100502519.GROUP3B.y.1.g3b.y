%{

#include <stdio.h>
#include <string.h>
int yylex(void);
void yyerror(const char *message);
double result;
int valid=0;
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

line    : expr           {result=$1;}//printf("%.1f\n", $1);
	;
expr    : expr expr'+'   {$$=$1+$2;}
        | expr expr'-'  {$$=$1-$2;}
        | expr expr'*'  {$$=$1*$2;}
        | expr expr'/'   {$$=$1/$2;}
        | RNUMBER
        ;

%%

void yyerror (const char *message) {
valid=1;   
fprintf (stderr, "%s\n", "Wrong Formula");
}

int main(int argc, char *argv[]) {
        yyparse();
	if(valid!=1){printf("%.1f\n", result);}
        return 0;
}
