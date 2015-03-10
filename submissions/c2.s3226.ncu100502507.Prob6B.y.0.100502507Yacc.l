%{
#include "100502507Yacc.tab.h"
%}

%%

\n				{ return 0;  }
[ \t]                   	{ /*Do nothing*/ }
[0-9]+(\.[0-9]*)?		{ yylval.rval = atof(yytext); return REALNUMBER; }
"\\frac"			{ yylval.word = strdup(yytext); return FRAC; }
("+""-""^""("")""{""}")		{ return yytext[0]; }
.				{ return yytext[0]; }

%%
