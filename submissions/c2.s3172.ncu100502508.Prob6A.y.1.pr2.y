%{
#include <stdio.h>
#include <string.h>
void yyerror(const char *message);
%}
%union{
int ival;
char* word;
}
%token<ival> INUMBER
%token<word> WORD
%type<ival> integer
%type<word> test
%%
line :test test integer {printf("first: %s second: %s \n%d\n",$1,$2,$3);}
     ;
test : WORD
     ;
integer :INUMBER {$<word>0,$<word>-1,$<ival>1;}
          ;
%%
void yyerror(const char *message)
{	
	fprintf(stderr, "%s\n",message);
}int main(int argc, char *argv[])
{
    yyparse();
    return(0);
}

