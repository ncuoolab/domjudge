%{
#include<stdio.h>
%}
ip			^[0-9]{0,3}\.[0-9]{0,3}\.[0-9]{0,3}\.[0-9]{0,3}
%%
{ip}	{printf("%s\n", yytext);}
.|\n	{}
%%
int main(){
	yylex();
	return 0;
}
