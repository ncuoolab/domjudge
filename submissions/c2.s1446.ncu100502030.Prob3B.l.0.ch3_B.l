
name		[A-Z][a-z]*
career		[a-zA-Z]+
favorite	[a-zA_Z]+
hometown	[A-Z][a-z]*
line		{name}[ \t]+{career}[ ]+noodles[ \t]+{hometown}
%%
{line}		{ ECHO; printf("\n"); }
.|\n		;

%%
 int main(int argc, char *argv[]) {
	yylex();
 	return(0);
}