%{
#include "ex.tab.h"
%} 
dnumber [0-9]+\.[0-9]* 
line \n 
%%  
{dnumber} {yylval.dval=atof(yytext);return(DNUMBER);} 
"+"|"-"|"*"|"/" {return(yytext[0]);} 
[ \t]+ ; 
. ; 
{line} {return(0);} 
%%
