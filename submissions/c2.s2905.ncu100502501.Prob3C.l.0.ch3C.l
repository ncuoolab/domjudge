%{
#include <stdio.h>
int i;
int j;
%}
dg	[0-9A-Fa-f]{1,8}
check   [0][X]|[0][x]
print   ^{check}{dg}$
print2   ^[ |\t]*{check}{dg}$
space    [ ]*
%%
{print} {ECHO;printf("\n");}
{print2} {for(i=0;i<yyleng;i++)
{if(yytext[i]!=' '&&yytext[i]!='\t'){printf("%c",yytext[i]);}};printf("\n");}
.|\n|{space}       {/* */}
%%

int main(int argc, char *argv[]) {
        yylex();
        return(0);
}
