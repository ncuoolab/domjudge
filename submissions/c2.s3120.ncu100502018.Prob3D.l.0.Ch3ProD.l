%{
%}
one	[0-9]
two	[1-9][0-9]
three	[12][0-9][0-9]
ran	{one}|{two}|{three}
IP	^{ran}\.{ran}\.{ran}\.{ran}
%%
{IP}	{ ECHO; printf("\n"); }
.|\n	;
%%
int main() {
	yylex();
	return 0;
}

