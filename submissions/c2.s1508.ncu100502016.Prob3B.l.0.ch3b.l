%{
%}
word	[a-zA-Z0-9]+
matchRow {word}[ \t]+{word}[ \t]+noodles[ \t]+{word}
%%
{matchRow}	{ ECHO; printf("\n"); }
.|\n	;
%%
int main(int argc, char *argv[]) {
	yylex();
	return(0);
}

