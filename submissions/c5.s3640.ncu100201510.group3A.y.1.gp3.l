%{
#include "gp3.tab.h"
%}
%%

\n	{ return(0); /* EOF */ }
[ \t]+	{ /* do nothing */ }
[0-9]+(\.[0-9]*)?	{ yylval.rval = atof(yytext); return(RNUMBER); ECHO;}
"+"|"-"|"*"|"/"|"("|")"	{ return(yytext[0]); ECHO;}
.	{ return(yytext[0]); }

%%

