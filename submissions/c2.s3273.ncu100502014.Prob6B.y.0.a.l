%{
#include "a.tab.h"
%}
%%
\n {return(0);}
[ \t]+ {}
[0-9]+ {yylval = atoi(yytext);return(INUMBER);}
"+"|"-"|"("|")"|"^"|"{"|"}" {return(yytext[0]);}
(%\frac) {yylval.word = strdup(yytext);return WORD;}
. {return(yytext[0]);}
%%
