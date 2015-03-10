
name		[A-Z][a-z]*
career		[a-zA-Z]+
favorite	[a-zA_Z]+
hometown	[A-Z][a-zA-Z]*
word		[A-Za-z]+
line		{word}[ \t]+{word}[ \t]+noodles[ \t]+{word}
%%
{line}		{ ECHO; printf("\n"); }
.|\n		;

%%
 int main(int argc, char *argv[]) {
	yylex();
 	return(0);
}
