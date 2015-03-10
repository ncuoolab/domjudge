%{
#include "group.tab.h"
%}
%%

\n	{ return(0); /* EOF */ }
[ \t]+	{ /* do nothing */ }
[0-9]+	{ yylval.word = strdup(yytext);return WORD; }
"+"|"-"|"*"|"/"|"("|")"	{ return(yytext[0]); }
.	{ return(yytext[0]); }

%%