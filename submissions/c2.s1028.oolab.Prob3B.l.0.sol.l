%{
#include<stdio.h>
%}
char	[a-zA-Z0-9]
word	{char}*
sep	[ \t\n]*
target	^{sep}{word}{sep}{word}{sep}noodles{sep}{word}{sep}$
%%
{target}	printf("%s\n", yytext);
.|\n		{}
%%

int main(){
	yylex();
	return 0;
}
