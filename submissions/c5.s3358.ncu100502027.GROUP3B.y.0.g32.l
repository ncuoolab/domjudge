%{
#include "g32.tab.h"
%}
%%

[0-9]+(\.[0-9]*)? {yylval.rval= atof(yytext); return(RNUMBER);}
[ \t\n.] {}
(\+) { return('+');}
(-) { return('-');}
(\*) { return('*');}
(/) { return('/');}

%%