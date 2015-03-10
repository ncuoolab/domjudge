%{
#include <stdio.h>
#include <string.h>
void yyerror(const char *message);
%}
%union{
double ival;
}
%token<ival> number
%type<ival> E
%%
line : E	{printf("%.1f\n", $1);}
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
    printf("Wrong Formula.\n");
}
int main(int argc, char *argv[])
{
    yyparse();
    return(0);
}

