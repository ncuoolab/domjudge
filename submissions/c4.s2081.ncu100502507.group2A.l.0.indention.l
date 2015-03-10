%{
	unsigned int indention_counter = 0;
	void printIndention(unsigned int);
%}

bracket_l	['{']
bracket_r	['}']
%x		COMMENT

%%

\t			{ /*Do nothing.*/ }
<COMMENT>{bracket_l}	{ ECHO; indention_counter++; }
<COMMENT>{bracket_r}	{ indention_counter--; printIndention(indention_counter); ECHO; }
<COMMENT>\n		{ ECHO; BEGIN INITIAL; }
<COMMENT>.		{ ECHO; }
<COMMENT>\t		{ /*Do nothing.*/ }
{bracket_l}		{ printIndention(indention_counter); ECHO; indention_counter++; BEGIN COMMENT; }
{bracket_r}             { indention_counter--; printIndention(indention_counter); ECHO; BEGIN COMMENT; }
(' ')			{ /*Do nothing.*/ }
.			{ printIndention(indention_counter); ECHO; BEGIN COMMENT; }

%%

int main(int argc, char *argv[]) {
	yylex();
	return 0;
}

void printIndention(unsigned int total) {
	unsigned int counter = NULL;
	while(counter < total) {
		printf("%s", "\t");
		counter++;
	}
}
