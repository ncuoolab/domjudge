%{
#include "LE.tab.h"
%}
%%

\n	{ return(0); /* EOF */ }
[ \t]+	{ /* do nothing */ }
[0-9]+	{ yylval.ival= atoi(yytext); return(DNUMBER); }
(\\frac) {return '@';}
"+"|"-"|"*"|"("|")"|"^"	{ return(yytext[0]); }
.	{ return(yytext[0]); }

%%



