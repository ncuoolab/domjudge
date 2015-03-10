%{
#include <stdio.h>
%}
dg	[0-9|A-F|a-f]{1,8}
check   [0][X]|[0][x]
print   ^{check}{dg}$

%%
{print} {ECHO;printf("\n");}
.|\n       {/* */}
%%

int main(int argc, char *argv[]) {
        yylex();
        return(0);
}
