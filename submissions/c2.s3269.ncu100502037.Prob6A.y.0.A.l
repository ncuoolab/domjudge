%{
#include "A.tab.h"
%} 
%% 

[ \t\n]+ { /* do nothing */ } 
[0-9]+ {yylval.ival= atoi(yytext); return(INUMBER); } 
add   {return ('+'); }
sub   {return ('-'); }
mul   {return ('*'); }
mod   {return ('%'); }
load  {}

"+"|"("|")"	{ return(yytext[0]); }
.	{ return(yytext[0]); } 

%%
