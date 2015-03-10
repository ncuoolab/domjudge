%{
#include <stdio.h>
#include <string.h>
#include <math.h>
int yylex(void);
void yyerror(const char *msg);
%}
%union{
        double rval;
        char *word;
}
%token <rval>   RNUMBER
%token <word>   WORD
%type <rval>    expr
%left '+' '-'
%left '^'
%right UMINUS

%%

line    : expr                  {printf("%.3f\n", $1);}
        ;
expr    : expr '+' expr         {$$ = $1+$3;}
        | expr '-' expr         {$$ = $1-$3;}
        | '(' expr ')'          {$$ = $2;}
        | WORD '{'expr'}''{'expr'}'     {$$ = $3/$6;}
        | expr '^' '{'expr'}'           {$$ = pow($1,$4);}
        | expr '^' RNUMBER      {$$ = pow($1,$3);}
        | '-' expr %prec UMINUS {$$ = -$2;}
        | RNUMBER
        ;
%%

void yyerror (const char *msg)
{
        /*msg = "Invalid";*/
        fprintf(stderr, "%s\n", "Invalid format");
}

int main(int argc, char *argv[])
{
        yyparse();
        return 0;
}


