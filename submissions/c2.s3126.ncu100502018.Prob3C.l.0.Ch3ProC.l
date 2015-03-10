%{
%}
hex	0[xX][0-9a-fA-F]{1,8}$
not	[0-9a-zA-Z]{hex}
%%
{hex}	{ ECHO; printf("\n"); }
{not}	;
.|\n	;
%%
int main() {
	yylex();
	return 0;
}
