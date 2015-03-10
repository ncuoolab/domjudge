letter	[a-zA-Z_]
word    {letter}+
space	[ |\t]
identifier {word}{space}+{word}{space}+noodles{space}+{word}
%%
{identifier} {ECHO;printf("\n");}
.|\n	{/*do nothing*/}

%%
int main(int argc, char* argv[])
{
	yylex();
	return(0);
}
