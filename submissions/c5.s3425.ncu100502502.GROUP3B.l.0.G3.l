%{
#include "G3.tab.h"
%}
%%
\n      { return(end); /* EOF */ }
[ \t]+  { /* do nothing */ }
[0-9]+(\.[0-9]*)?       { yylval.ival= atof(yytext); return(number); }
"+"|"-"|"*"|"/"   {return(yytext[0]);}
.       { return(yytext[0]); }
%%

