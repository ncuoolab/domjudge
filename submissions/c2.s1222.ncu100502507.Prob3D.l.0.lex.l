number		[0-255]
dot		["."]
ipAddress	{number}{dot}{number}{dot}{number}{dot}{number}
specialSymbol	("\n")|("\t")|(" ")|("\r")

%%

{specialSymbol}	{ //Do nothing }
{ipAddress}	{ ECHO; printf("\n"); }
.		{ //Do nothing }

%%

int main(int argc, char *argv[]) {
	yylex();	
	return 0;
}
