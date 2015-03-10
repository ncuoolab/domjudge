%{
#include "ex.tab.h"
%}
dnumber	[0-9]+
frac	\\frac
line	\n
%%
{frac}	{yylval.word=strdup(yytext);return(WORD);}
{dnumber}	{yylval.ival=atof(yytext);return(DNUMBER);}
"+"|"-"|"("|")"|"^"	{return(yytext[0]);}
[ \t]+	;
.	{return(yytext[0]);}
{line}	{return(0);}
%%

