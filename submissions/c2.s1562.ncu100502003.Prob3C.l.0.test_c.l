%{
	#include <stdio.h>
%}
letter		[A-Fa-f]
digit		[0-9]
scope		"("({letter}|{digit})+")"
hex_literal	^0(x|X)({letter}|{digit}|{scope}){1,8}$

%%
{hex_literal}	{ECHO; printf("\n");}
.		{}
\n		{}
%%

int main()
{
	yylex();
	return(0);
}
