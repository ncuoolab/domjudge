%{
#include <stdio.h>
#include <string.h>
void yyerror(const char *message);
double answer=0;
int valid = 1;
%}
%union {
double dval;
}
%token <dval> dnumber
%type <dval> expr
%left '+''-'
%left '*''/'
%%
line    : expr     {answer=$1;}         
;
expr 	:expr  expr '*' 	{$$=$1*$2;}
		|expr  expr '+'  	{$$=$1+$2;}
		|expr  expr '-'  	{$$=$1-$2;}
		|expr  expr '/'      {$$=$1/$2;}
		|dnumber 			{$$=$1;}
;
%%
void yyerror (const char *message)
{
      valid = 0;
	  printf("Wrong Formula\n");
}

int main(int argc, char *argv[]) {
        yyparse();
		if(valid==1){
			printf("%.1f\n",answer);
		}
        return(0);
}

