%{
#include "group.tab.h"
%}
%%

\n	{ return(0); /* EOF */ }
[ \t]+	{ /* do nothing */ }
[0-9]+(\.[0-9]*)?	{ return(NUM); }
"+"|"-"|"*"|"/"|"("|")"	{ return(yytext[0]); }
.	{ return(yytext[0]); }

%%