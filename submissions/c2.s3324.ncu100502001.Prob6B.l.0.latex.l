%{
#include "y.tab.h"
%}
real	[0-9]+([\.][0-9]*)?
frac	"frac"
%%
\n	{return(yytext[0]);/*EOF*/}
[ \t]+	{/*do nothing*/}
{real}	{yylval.rval = atof(yytext);return(RNUMBER);}
[\+\-\^\(\)\{\}\\]	{return(yytext[0]);}
{frac}	{return(FRAC);}
.	{return(yytext[0]);}
%%
