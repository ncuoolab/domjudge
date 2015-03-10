%{
	unsigned int charCount=0, wordCount=0, lineCount=0;
%}
digit		[0-9]
character	[a-zA-Z]
underline	[_]
dollarSym	["$"]
identifier	({character}|{underline}|{dollarSym})({digit}|{character}|{underline}|{dollarSym})*
matched		{identifier}*("cpy")+{identifier}*
type		("int")|("double")
specialSym	("\n")|("\t")|(" ")|("\r")

%%

{specialSym}	{ /*Do nothing*/ }
{type}		{ /*ECHO; printf(" is a type.\n");*/ }
{matched}	{ ECHO; printf("\n"); /*printf(" is a matched identifier.\n");*/ }
{identifier}	{ /*ECHO; printf(" is an identifier.\n");*/ }
.		{ /*Do nothing*/ }

%%

int main(int argc, char *argv) {
	yylex();
	return 0;
}
