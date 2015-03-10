%{
#include "y.tab.h"
%} 
%% 
[0-9]+(\.[0-9]+)? { yylval.fval=atof(yytext);return RNUMBER; } 
"+"|"-"|"*"|"/"|"%"|"("|")" { return yytext[0]; } 
[\n] { return 0; } 
[\t] {} 
. {return yytext[0];/* yyerror("invalid charcter");*/ } 

%%
