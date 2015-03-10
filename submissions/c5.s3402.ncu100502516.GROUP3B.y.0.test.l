%{
#include "test.tab.h"
%}
%%
[\n]    {return(0);}
[ \t]+  { /* do nothing */ }
[0-9]+(\.[0-9]*)?  { yylval.rval = atof(yytext); return(RNUM); }
.       { return(yytext[0]); }
%%

