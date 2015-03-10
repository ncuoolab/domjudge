%{
#include "6a.tab.h"
%}

%%
\n		{}
[ \t]+		{}
[0-9]+(\.[0-9]+)?	{yylval.ival=atof(yytext); return INUMBER;}
"load"		{}
"add"		{return '+';}
"sub"		{return '-';}
"mul"		{return '*';}
"mod"		{return '%';}
"inc"		{return '>';}
"dec"		{return '<';}
"+"|"-"|"("|")"	{return yytext[0];}
.		{return yytext[0];}
%%
