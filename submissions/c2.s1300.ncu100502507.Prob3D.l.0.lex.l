digit		[0-9]
dot		["."]
number		([1]{digit}{2})|([2][0-4]{digit})|([2][5][0-5])|({digit}{2,3})|({digit})
ipAddr		({number}{dot}{number}{dot}{number}{dot}{number})
duplicateAddr	{ipAddr}(" ")*({digit}|{dot})+
specialSymbol	("\n")|("\t")|(" ")|("\r")

%%

{duplicateAddr}	{ /*Do nothing*/ }
{ipAddr}	{ ECHO; printf("\n"); }
{specialSymbol} { /*Do nothing*/ }
.		{ /*Do nothing*/ }

%%

int main(int argc, char *argv) {
	yylex();	
	return 0;
}
