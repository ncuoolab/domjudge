%{
#include "test1.tab.h"
%}
%x	digit
%%
[ \t]+	{ /* do nothing */ }
load		{;}
[0-9]+	{yylval.num = atoi(yytext); return(NUMBER); BEGIN INITIAL;}
add		{ return ('+');}
sub             { return ('-');}
mul             { return ('*');}
mod             { return ('%');}
inc             {yylval.word = strdup(yytext); return (INC);}
dec             {yylval.word = strdup(yytext); return (DEC);}
\n		;
.		{;}
%%

