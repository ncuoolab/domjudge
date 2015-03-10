%{
#include "ext1.tab.h"
%}

frac_head	"\frac"
float		[0-9]+("."[0-9]*)?
%%
{float}						{/*printf("lex (%.3lf)\n", atof(yytext));*/ yylval.fval = atof(yytext); return NUMBER;}
"+"|"-"|"^"|"("|")"|"{"|"}" { return yytext[0]; }
\\frac	{return FRAC_HEAD;}
\n			{}
.			{}
%%
