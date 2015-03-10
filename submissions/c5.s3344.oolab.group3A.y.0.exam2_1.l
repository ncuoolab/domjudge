%{

#include "exam2_1.tab.h"
%}

%%

[0-9]+ { yylval.ival=atoi(yytext);return INUMBER; }

"+"|"-"|"*"|"/"|"%"|"("|")" { return yytext[0]; }

[\n]  {return 0;}

[\t] {}


. {/*return yytext[0];*/ /* yyerror("invalid charcter");*/ }


%%
