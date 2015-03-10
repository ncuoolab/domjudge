%{
#include "ch6.tab.h"
%}
%%

[ \t\n.] {}
[0-9]+ {yylval.rval= atoi(yytext); return(INUMBER);}
(load) {}
(add) { return('+');}
(sub) { return("-");}
(mul) { return("*");}
(mod) { return("%");}
(inc) { return("++");}
(dec) { return("--");}

%%