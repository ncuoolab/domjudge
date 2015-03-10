%{
#include<stdio.h>
%}
hex		^0(x|X)[0-9A-Fa-f]{1,8}
%%
{hex}	{printf("%s\n", yytext);}
.|\n	{}
%%
int main(){
	yylex();
	return 0;
}
