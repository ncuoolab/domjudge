%{
#include "LaTex.tab.h"
%}
num		[0-9]+(\.[0-9]+)?
%%

\n				{return(0);}
[ \t]+				{}
{num}				{yylval.rval=atof(yytext); return(RNUMBER);}
"\\frac"                        {yylval.word=strdup(yytext); return(WORD);}
"^"|"{"|"}"			{return(yytext[0]);}
.				{return(yytext[0]);}

%%

