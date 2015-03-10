%{
#include <stdio.h>
%}
%option noyywrap

%%
[a-zA-Z_][a-zA-Z_0-9]*    {if(strstr(yytext, "cpy") != NULL) ECHO;printf("\n");}

.       { }

%%
int main(void)
{
    yylex();
    return 0;
}