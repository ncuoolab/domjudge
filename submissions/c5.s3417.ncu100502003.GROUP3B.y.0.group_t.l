%{
#include "group_t.tab.h"
%}

%%
\n			{return(0);}
[\t]+			{}
[ ]			{return '@';}
[0-9]+(\.[0-9]+)?	{yylval.rval=atof(yytext); return(NUMBER);}
'+'			{return '+';}
'-'			{return '-';}
'*'			{return '*';}
"//"			{return '/';}
.			{return(yytext[0]);}

%%
