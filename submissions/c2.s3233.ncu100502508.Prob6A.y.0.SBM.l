%{
#include "SBM.tab.h"
%}
%%
[ \t\n]+	{ /* do nothing */ }
[0-9]+	{ yylval.ival= atoi(yytext); return(INUMBER); }
load	{/*do nothing*/}
add	{return('+');}
sub     {return('-');}
mul     {return('*');}
mod     {return('%');}

"+"|"-"|"*"|"/"|"%"|"("|")"	{ return(yytext[0]); }
.	{ /*do nothing*/ }

%%



