%{
#include "gp3.tab.h"
%}
%%

\n	{ return(0); /* EOF */ }
[ \t]+	{ /* do nothing */ }
[0-9]+	{ yylval.rval = atoi(yytext); return(RNUMBER); }
"+"|"-"|"*"|"/"|"("|")"	{return(yytext[0]); }
.	{ return(yytext[0]); }

%%


