%{
	unsigned int indention_counter = 0;
	void printIndention(unsigned int);
%}

bracket_l	[{]
bracket_r	[}]
brackets	[{bracket_l}{bracket_r}]
space		[ ]
tab		["\t"]
tabBrL		{tab}*{bracket_l}
tabBrR		{tab}*{bracket_r}
%x		COMMENT

%%

<COMMENT>{bracket_l}	{ ECHO; indention_counter++; }
<COMMENT>{bracket_r}	{ indention_counter--; ECHO; }
<COMMENT>\n		{ ECHO; BEGIN INITIAL; }
<COMMENT>.		{ ECHO; }
{tabBrR}		{ indention_counter--; printIndention(indention_counter); printf("}"); BEGIN COMMENT; }
{tabBrL}		{ printIndention(indention_counter); printf("{"); indention_counter++; BEGIN COMMENT; }
{tab}*			{ printIndention(indention_counter); BEGIN COMMENT; }
{space}			{ /*Do nothing.*/ }
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
