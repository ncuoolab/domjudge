%{
#include "100502507group.tab.h"
%}

%%

\n				{ return 0;  }
[ \t]                   	{ /*Do nothing*/ }
[0-9]+				{ yylval.ival = atof(yytext); return INTEGER; }
("+""-""*""/""("")")		{ return yytext[0]; }
.				{ return yytext[0]; }

%%
