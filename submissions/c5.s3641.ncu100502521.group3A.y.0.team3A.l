%{
#include "team3A.tab.h"
%}
%%
\n	{ return(0);}
[ \t]+	{ /* do nothing */ }
[0-9]+	{ yylval.ival= atoi(yytext); return(INUMBER); }
.	{ return(yytext[0]); }

%%

