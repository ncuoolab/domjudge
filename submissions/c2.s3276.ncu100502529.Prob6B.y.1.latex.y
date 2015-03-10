%{
#include <stdio.h>
#include <math.h>
void yyerror(const char *message);
double answer = 0.0;
int isError = 0;
%}
%union{
double dval;
}
%token <dval>dnum
%token frac
%type  <dval>Expr
%type  <dval>Frac
%type  <dval>Expo
%left '+' '-'
%right '^'
%%
Start : Expr                               { answer=$1; }
      ;
Frac  : frac '{' Expr '}' '{' Expr '}'     { $$=$3/$6; }
      ;
Expo  : dnum '^' dnum                      { $$=pow($1,$3); }
      | '(' Expr  ')' '^' dnum             { $$=pow($2,$5); }
      | dnum '^' '{' Expr '}'              { $$=pow($1,$4); }
      | '(' Expr ')' '^' '{' Expr '}'      { $$=pow($2,$6); }
      ;
Expr  : Expr '+' Expr                      { $$=$1+$3; }
      | Expr '-' Expr                      { $$=$1-$3; }
      | '(' Expr  ')'                      { $$=$2; }
      | Frac                               { $$=$1; }
      | Expo                               { $$=$1; }
      | dnum
      ;
%%
void yyerror(const char *message)
{
  isError = 1;
  printf("Invalid format\n");
} 

int main(int argc, char *argv[])
{
  yyparse();
  if(isError == 0)
  {
    printf("%.3lf\n",answer);
  }
  return(0);
}
