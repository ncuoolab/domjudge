%{
#include "ex1.tab.h"
%}
white		[ \t]+
digit		[0-9]
integer 	{digit}+
real		{integer}("."{integer})?

%%
\n		{ return(0); /* EOF */ }
{white}		{ /* do nothing */ }
{real}		{ yylval.dval = atof(yytext);return(RNUMBER); }
"+"|"-"|"*"|"/"	{ return(yytext[0]); }
.		{ return(yytext[0]); }
%%
