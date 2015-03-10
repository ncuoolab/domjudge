n1hex	[^ \t\n]+0(x|X)[a-fA-F0-9]{1,8}[^ \t\n]+
n2hex	[^ \t\n]+0(x|X)[a-fA-F0-9]{1,8}
n3hex	0(x|X)[a-fA-F0-9]{1,8}[^ \t\n]+
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
