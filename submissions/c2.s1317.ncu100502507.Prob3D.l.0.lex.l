digit		[0-9]
dot		["."]
number		([1]{digit}{2})|([2][0-4]{digit})|([2][5][0-5])|({digit}{digit})|({digit})
ipAddr		({number}{dot}{number}{dot}{number}{dot}{number})
specialSymbol	("\n")|("\t")|(" ")|("\r")

%%

{ipAddr}	{ ECHO; printf("\n"); }
{specialSymbol} { /*Do nothing*/ }
.		{ /*Do nothing*/ }

%%

int main(int argc, char *argv) {
	yylex();	
	return 0;
}
