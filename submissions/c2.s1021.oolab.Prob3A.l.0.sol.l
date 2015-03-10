%{
#include<stdio.h>
%}

head		[a-zA-Z_]
tail		{head}|[0-9]
target1		cpy{tail}*
target2		{head}{tail}*cpy{tail}*
target		{target1}|{target2}
%%
{target}	printf("%s\n", yytext);
.|\n		{}
%%

int main(){
	yylex();
	return 0;
}
