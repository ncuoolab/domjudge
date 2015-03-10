%{
#include <stdio.h>
unsigned int count=0;
int i;
%}
brl	"{"[^\t\n]*
brr	"}"[^\n\t]*
print   [^\n\t{}]+
eol	[\n]
%%
{brl}	{for(i=0; i<count; i++) printf("\t");ECHO;count++;}
{brr}   {count--; for(i=0; i<count; i++) printf("\t");ECHO;}
{eol}   {ECHO;}
{print} {for(i=0; i<count; i++) printf("\t");ECHO;}
.       {/* */}

%%

int main(int argc, char *argv[]) {
        yylex();
        return(0);
}
