letter	[a-zA-Z_]
digit	[0-9]
id	{letter}*"cpy"({letter}|{digit})*
%%
{id}	{ECHO;printf("\n");}
.|\n    ;
%%
int man(int argc, char *argv[]) {
	yylex();
	return(0);
}

