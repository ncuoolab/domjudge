%{
#include"GROUP3B.tab.h"
%}
%%
\n			{return(0);}
[ \t]			{}
[0-9]+(\.[0-9]*)?	{yylval.rval = atof(yytext);return(RNUMBER);}
"+"|"-"|"*"|"/"		{return(yytext[0]);}
.			{return(yytext[0]);}
%%