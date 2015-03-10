%{
#include "g32.tab.h"
%}
%%

[ \t\n.]+	{  }
[0-9]+	{ yylval.rval = atof(yytext); return(RNUMBER); }
"+"|"-"|"*"|"/"|"("|")"	{ return(yytext[0]); }
%%