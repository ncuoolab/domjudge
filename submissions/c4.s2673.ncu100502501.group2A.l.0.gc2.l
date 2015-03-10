%{
#include <stdio.h>
unsigned int count=0;
int i;
%}
brl	[^}\t\n]*"{"
brl1	"{//"[^\t\n{}]*	
brr   	 "}"[^{\n\t]*
brr2	[^{\n\t]+"}"[^{\n\t]*
print   [^\n\t{}]+
br	{brl}|{brl1}
eol	[\n]
space	" "
%%
{br}	{for(i=0; i<count; i++) printf("\t");ECHO;count++;}
{brr2}	{count--; ECHO;}
{brr}   {count--; for(i=0; i<count; i++) printf("\t");ECHO;}
{eol}   {ECHO;}
{space}	{}
{print} {for(i=0; i<count; i++) printf("\t");ECHO;}
.       {/* */}

%%

int main(int argc, char *argv[]) {
        yylex();
        return(0);
}
