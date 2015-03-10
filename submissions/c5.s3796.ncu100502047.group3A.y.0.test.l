%{
#include"test.tab.h"
%}
digit	[0-9]
integer	{digit}+
%%
\n	{return(0);}
[ \t]	{}
{integer}	{yylval.i = atoi(yytext); return(INTEGER);}
"+"|"-"|"*"|"/"|"("|")"	{return(yytext[0]);}
.	{return(yytext[0]);}
%%
