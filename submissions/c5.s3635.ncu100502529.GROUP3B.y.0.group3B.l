%{
#include "group3B.tab.h"
%}
digits        [0-9]+
float         {digits}[.]{digits}
real          {digits}|{float}
blank         [ ]
operator      "+"|"-"|"*"|"/"
%x            S
%%
\n            { return(0); }
[ \t]+        ;
{real}        { BEGIN S; yylval.rval=atof(yytext); return(rnum); }
<S>\n         { return(0); }
<S>{real}     { yylval.rval=atof(yytext); return(rnum); }
<S>{blank}    { return(yytext[0]); }
<S>{operator} { return(yytext[0]); }
<S>.          { return(yytext[0]); }
.             { return(yytext[0]); }
%%
