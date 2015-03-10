%{
#include "ex2.tab.h"
%}
%%

\n	{ return(0); /* EOF */ }
[ \t]+	{ /* do nothing */ } 
[0-9]+(\.[0-9]*)?	{ yylval.ival = atoi(yytext); return(INUMBER); } 
"+"|"-"|"*"|"/"|"("|")"	{ return(yytext[0]); }
[a-zA-Z]+   {}
.	{ return(yytext[0]); }
%%
