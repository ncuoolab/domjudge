%{
#include <stdio.h>
%}
%option noyywrap

num       ([0-9] | [1-9][0-9] | [1][0-9][0-9] | [2][0-4][0-9] | [2][5][0-5])

%%
[0-9] | [1-9][0-9] | [1][0-9][0-9] | [2][0-4][0-9] | [2][5][0-5]    {ECHO; print("\n");}


[num]"."[num]"."[num]"."[num] {
ECHO;
}

. {}

%%
int main()
{
    yylex();
    return 0;
}