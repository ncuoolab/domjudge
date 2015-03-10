%{
	unsigned int indention_counter = 0;
%}
bracket_l	['{']
bracket_r	['}']

%%

{bracket_l}	{ indention_counter++; }
{bracket_r}	{ indention_counter--; }

%%

int main(int argc, char *argv[]) {
	yylex();
	return 0;
}
