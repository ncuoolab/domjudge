%{
#include <stdio.h>
#include <string.h>
%}
%option noyywrap

%%
[a-zA-Z_][a-zA-Z_0-9]*    {if(strstr(yytext, "cpy") != NULL) printf(yytext + "\n"); }

.       { }

%%
int main(void)
{
    yylex();
    return 0;
}