%{
#include "latex.tab.h"
%}
digits   [0-9]+
space    [ \t]+
operator "+"|"-"|"^"|"("|")"|"{"|"}"
%%
\n         { return(0); }
{space}    ;
{digits}   { yylval.dval=atof(yytext); return(dnum); }
"\frac"    { return(frac); }
{operator} { return(yytext[0]); }
.          { return(yytext[0]); }
%%
