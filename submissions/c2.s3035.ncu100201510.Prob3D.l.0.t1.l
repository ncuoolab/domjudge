%{
#include <stdio.h>

%}
%option noyywrap

num       [0-9]|[1-9][0-9]|[1][0-9][0-9]|[2][0-4][0-9]|[2][5][0-5]

ip        {num}"."{num}"."{num}"."{num}

%%
[ ]*{ip}[ ]* {ECHO;}

. {}

%%
int main()
{
    yylex();
    return 0;
}