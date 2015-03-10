%{
#include "ex.tab.h"
%}
inumber	[0-9]+
sub	(sub)
add	(add)
inc	(inc)
dec	(dec)
mod	(mod)
mul	(mul)
line	\n
%%
"load"	;
{add}	{return('+');}
{sub}	{return('-');}
{mod}	{return('%');}
{mul}	{return('*');}
{inc}	{return('i');}
{dec}	{return('d');}
{inumber}	{yylval.ival=atoi(yytext);return INUMBER;}
{line}	;
[ \t]+	;
.	{return(yytext[0]);}
%%