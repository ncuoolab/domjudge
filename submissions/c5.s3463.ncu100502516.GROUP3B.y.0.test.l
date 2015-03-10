%{
#include "test.tab.h"
%}
%%
[ \t\n]+  { /* do nothing */ }
[0-9]+(\.[0-9]*)?  { yylval.rval = atof(yytext); return(RNUM); }
.       { return(yytext[0]); }
%%

