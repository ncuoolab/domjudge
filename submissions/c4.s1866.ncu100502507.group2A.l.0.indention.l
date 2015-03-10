%{
	unsigned int indention_counter = 0;
	void printIndention(unsigned int);
%}

bracket_l	['{']
bracket_r	['}']
%x		COMMENT

%%

{bracket_l}	{ indention_counter++; ECHO;}
{bracket_r}	{ indention_counter--; ECHO;}
\n		{ ECHO; BEGIN COMMENT; }
<COMMENT>.	{ printIndention(indention_counter); ECHO; BEGIN INITIAL; }
.		{ ECHO; }

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
