n1hex	[^ \t]+0(x|X)[a-fA-F0-9]{1,8}[^ \t]+
n2hex	[^ \t]+0(x|X)[a-fA-F0-9]{1,8}
n3hex	0(x|X)[a-fA-F0-9]{1,8}[^ \t]+
hex	0(x|X)[a-fA-F0-9]{1,8}
%%
{n1hex}	;
{n2hex} ;
{n3hex} ;
{hex}	{ ECHO; printf("\n"); }
.|\n	;
%%
int main(int argc, char *argv[]) {
	yylex();
 	return(0);
}
