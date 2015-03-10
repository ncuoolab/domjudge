
%{
#include "ex1.tab.h"
%}
%%
\n		{ return(0); /* EOF */ }
[ \t]+		{ /* do nothing */ }
[0-9]+(\.[0-9]*)?	{ yylval.rval = atof(yytext); return(RNUMBER); }
"\\frac"		{yylval.word = strdup(yytext); return WORD;}
"+"|"("|")"	{ return(yytext[0]); }
.		{ return(yytext[0]); }
%%


