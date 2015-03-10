%{
%}
word	^0[xX][0-9a-fA-F^ \t\n]{6}
%%
{word}	{ ECHO; printf("\n"); }
.|\n		{}
%%
int main(int argc, char *argv[]) {
	yylex();
	return(0);
}

