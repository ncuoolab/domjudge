%{ 
%}
hex	^0[xX][0-9a-fA-F]{1,8}$
%%
{hex}	{ ECHO; printf("\n"); }
.|\n	;
%%
int main() {
	yylex();
	return 0;
}
