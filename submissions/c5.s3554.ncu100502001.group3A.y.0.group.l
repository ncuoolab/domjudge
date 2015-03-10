%{
#include "group.tab.h"
%}
%%
\n	{return(0);}
[ \t]+	{}
[0-9]+	{yylval.ival=atoi(yytext);return(INUMBER);}
[\+\-\*\/\(\)]	{return(yytext[0]);}
.	{return(yytext[0]);}
%%

