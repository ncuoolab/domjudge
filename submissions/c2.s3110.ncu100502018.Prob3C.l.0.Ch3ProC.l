%{ 
%}
hex	^0[xX][0-9a-fA-F]{1,8}$
not	^[ \t\n]+0[xX][0-9a-fA-F]{1,8}
%%
{hex}	{ ECHO; printf("\n"); }
{not}	;
.|\n	;
%%
int main() {
	yylex();
	return 0;
}
