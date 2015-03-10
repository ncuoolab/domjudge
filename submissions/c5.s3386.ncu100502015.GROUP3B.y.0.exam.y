%{
#include <stdio.h>
#include <string.h>

void yyerror(const char *message);
double ans;
int flag=0;
%}
%union {
double rval;
}
%token <rval> RNUMBER
%type <rval> expr
%left '+''-'
%left '*''/'
%%
line    : expr                          {ans=$1;}
expr    : expr expr '+'                 {$$=$1+$2;}
        | expr expr '-'                 {$$=$1-$2;}
	| expr expr '*'			{$$=$1*$2;}
	| expr expr '/'			{$$=$1/$2;}       
        | RNUMBER
%%
void yyerror (const char *message) {
        printf ("Invalid format\n");
        flag=1;
}
int main(int argc, char *argv[]) {
        yyparse();
        if(flag!=1){
                printf("%.3f\n",ans);
        }
        return(0);
}

