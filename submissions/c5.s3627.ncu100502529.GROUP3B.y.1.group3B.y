%{
#include<stdio.h>
#include<string.h>
void yyerror(const char *message);
double answer;
int isError = 0;
%}
%union{
double rval;
}
%token <rval>rnum
%type <rval>Expr
%%
Line : Expr                 { answer=$1; }
     ;
Expr : Expr' 'Expr' ''+'    { $$=$1+$3; }
     | Expr' 'Expr' ''-'    { $$=$1-$3; }
     | Expr' 'Expr' ''*'    { $$=$1*$3; }
     | Expr' 'Expr' ''/'    { $$=$1/$3; }
     | rnum
     ;
%%
void yyerror(const char *message)
{
   isError = 1;
   printf("Wrong Formula\n");
}

int main(int argc, char *argv[])
{
   yyparse();
   if(isError == 0)
   {
     printf("%.1lf\n",answer);
   }
   return(0);
}
