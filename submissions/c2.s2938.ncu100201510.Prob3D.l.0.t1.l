%{
#include <stdio.h>
%}
%option noyywrap
num ([0-9] | [1-9][0-9] | [1][0-9][0-9] | [2][0-4][0-9] | [2][5][0-5])
%%

[num]"."[num]"."[num]"."[num]        {
			ECHO;
        }

.       {   /* 忽略所有其他的字*/   }

%%
int main()
{
    yylex();
    return 0;
}