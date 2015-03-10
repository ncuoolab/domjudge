%{
#include "g3.tab.h"
%}
%%

\n      { return(0); /* EOF */ }
[ \t]+  { /* do nothing */ }
[0-9]+  { yylval.ival = atof(yytext); return(INUMBER); }
"+"|"-"|"/"|"*"|"("|")"    {return(yytext[0]);}
.       { return(yytext[0]); }
%%

