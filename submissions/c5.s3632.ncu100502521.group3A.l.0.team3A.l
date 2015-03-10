%{
#include "team3A.yacc.h"
%}
%%
\n	{ return(0);}
[ \t]+	{ /* do nothing */ }
[0-9]+	{ yylval.ival= atoi(yytext); return(INUMBER); }
.	{ return(yytext[0]); }

%%

