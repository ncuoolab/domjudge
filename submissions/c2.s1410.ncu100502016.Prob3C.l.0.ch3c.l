%{
%}
word	0[xX][0-9a-fA-F^ \t\n]{6}
eol	\n
%%
{word}	{ ECHO; printf("\n"); }
{eol}	{   }
%%
int main(int argc, char *argv[]) {
	yylex();
	return(0);
}

