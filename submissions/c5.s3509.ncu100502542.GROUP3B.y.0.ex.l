%{
#include "ex.tab.h"
%} 
dnumber -?([0-9])+(\.)?([0-9])* 
%%  
{dnumber} {yylval.dval=atof(yytext);return(DNUMBER);} 
"+"|"-"|"*"|"/" {return(yytext[0]);} 
[ \t]+ ; 
. {return(yytext[0]);} 
"\n" {return(0);} 
%%
