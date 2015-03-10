digit		[0-9]
dot		["."]
number		([1]{digit}{2})|([2][0-4]{digit})|([2][5][0-5])|({digit}{digit})|{digit}
ip		({number}{dot}{number}{dot}{number}{dot}{number})
specialSymbol	("\n")|("\t")|(" ")|("\r")

%x		COMMENT

%%

{ip}		{ ECHO; printf("\n"); BEGIN COMMENT; }
<COMMENT>\n	{ BEGIN INITIAL; }
<COMMENT>.	{ /*Do nothing*/ }
{specialSymbol} { /*Do nothing*/ }
.		{ /*Do nothing*/ }

%%

int main(int argc, char *argv) {
	yylex();	
	return 0;
}
