%{
#include "a.tab.h"
%}
%%
\n	{ return(0); /* EOF */ }
[0-9]+(\.[0-9]*)?[ ]	{ yylval.rval = atof(yytext); return(RNUMBER); }
"+"|"-"|"*"|"/"	 { return(yytext[0]); }
[ ]	{/*do nothing*/}
.	{ return(yytext[0]); }
%%

