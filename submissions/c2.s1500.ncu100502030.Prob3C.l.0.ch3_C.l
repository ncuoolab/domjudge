nhex	[.^ \t]+(x|X)[a-fA-F0-9]{1,8}[.^ \t]
hex	0(x|X)[a-fA-F0-9]{1,8}
%%
{nhex}	;
{hex}	{ ECHO; printf(" is HEX\n"); }
.|\n	;
%%
int main(int argc, char *argv[]) {
	yylex();
 	return(0);
}
