%{
#include"test.tab.h"
%}
digit	[0-9]
number	{digit}+
%x INPUT
%%
\n	{}
[ \t]	{}
"add"	{return(ADD);}
"sub"	{return(SUB);}
"mul"	{return(MUL);}
"mod"	{return(MOD);}
"inc"	{return(INC);}
"dec"	{return(DEC);}
"load"	{}
{number} { yylval.ival = atoi(yytext); return(NUMBER);}
.	{return(yytext[0]);}
%%
