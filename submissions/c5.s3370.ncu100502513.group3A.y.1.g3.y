%{
#include <stdio.h>
#include <string.h>
#include <math.h>
void yyerror(const char *message);
%}
%union{
int ival;
char* word;
}
%token<ival> INUMBER
%type<ival> expr
%left '+' '-'
%left '*' '/'
%right neg
%%

line : expr        {printf("%d\n",$1);}
     ;
expr : expr'+'expr {$$=$1+$3;}
     | expr'-'expr {$$=$1-$3;}
     | expr'*'expr {$$=$1*$3;}    
     | expr'/'expr {$$=$1/$3;}
     | '('expr')'  {$$=$2;}   
     | '-'expr %prec neg {$$=-$2;}
     | INUMBER
     ;
%%

void yyerror(const char *message)
{
        fprintf(stderr, "Invalid format\n");
}

int main(int argc, char *argv[])
{
    yyparse();
    return(0);
}
