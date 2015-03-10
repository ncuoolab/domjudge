%{
#include "prob.tab.h"
%}
%%

\n	{ return(0); /* EOF */ }
[ \t]+	{ /* do nothing */ }
[0-9]+	{ yylval.rval = atof(yytext); return(RNUMBER); }
"+"|"-"|"^"|"("|")"	{ return(yytext[0]); }
(%\frac)		{ yylval.WORD = strdup(yytext); return word;}
.	{ return(yytext[0]); }

%%


