%{
#include "y.tab.h"
%}
%%

\n     				{ return(0); /* EOF */ }
[ ] 	 			{ yylval.cval = strdup(yytext); return space; }
[0-9]+(\.[0-9]*)?       	{ yylval.rval = atof(yytext); return(RNUMBER); }
"+"|"-"|"*"|"/"			{ return(yytext[0]); }
.       			{ return(yytext[0]); }

%%


