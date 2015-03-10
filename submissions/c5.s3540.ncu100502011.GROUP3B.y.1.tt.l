%{
#include "tt.tab.h"
%}
%%
"-"?[0-9]+"."?[0-9]*		{yylval.dval=atof(yytext);return(dnumber);}
["+"|"-"|"*"|"/"]           {return(yytext[0]);}
\n 							{return(0);}
[ ]						{return(yytext[0]);}
. 							{return(yytext[0]);}
%%
