%{
#include <stdio.h>
#include <string.h>
void yyerror(const char *message);
float a;
int on = 1;
%}
%union{
float ival;
}
%token<ival> number
%type<ival> E
%%
line : E	{a = $1;}
     ;
E  : E E '+'	{$$ = $1 + $2;}
   | E E '-'    {$$ = $1 - $2;}
   | E E '*'    {$$ = $1 * $2;}
   | E E '/'    {$$ = $1 / $2;}
   | number
   ;
%%
void yyerror(const char *message)
{
    on = 0;
    printf("Wrong Formula.\n");
}
int main(int argc, char *argv[])
{
    yyparse();
    if(on == 1)
	printf("Wrong Formula.");
    else{}
    return(0);
}

