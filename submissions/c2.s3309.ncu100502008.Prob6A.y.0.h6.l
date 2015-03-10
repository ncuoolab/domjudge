
%{
#include "h6.tab.h"
int yywrap(void){
   return(1);
}
%}
%%

\n	{return (yytext[0]);}
[0-9]+	{yylval.ival=atoi(yytext);return INUMBER;}
"load"	{yylval.word=strdup(yytext);return LOAD;}
"add\n"	{yylval.word=strdup(yytext);return ADD;}
"sub\n"	{yylval.word=strdup(yytext);return SUB;}
"mul\n" {yylval.word=strdup(yytext);return MUL;}
"mod\n"	{yylval.word=strdup(yytext);return MOD;}
"inc\n"	{yylval.word=strdup(yytext);return INC;}
"dec\n" {yylval.word=strdup(yytext);return DEC;}
[ \t]+	{ /* do nothing */ }
.	{}
%%
