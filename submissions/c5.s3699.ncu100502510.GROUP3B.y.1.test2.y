%{
#include <stdio.h>
#include <string.h>
int yylex(void);
void setValue(double);
void yyerror(const char *message);
double result=0.0;
int error=1 ;
%}
%union {
   double rval;
}
%token <rval> RNUMBER 
%type <rval> expr  
%%
line : expr                 {setValue($1);}
     ;
expr : expr  expr '+'       { $$ = $1 + $2; }
     | expr  expr '-'       { $$ = $1 - $2; }
     | expr  expr '*'       { $$ = $1 * $2; }
     | expr  expr '/'       { $$ = $1 / $2; }  
     |RNUMBER
     ; 
%%
void yyerror (const char *message) {    
 error=0;
}
void setValue(double a)
{
 result=a;
}

int main(int argc, char *argv[]){
	yyparse();        
	if(error==0)
           printf("Wrong Formula.\n");
	else
	{
	 printf("%.1f",result);
	}
         
        return 0;
}
