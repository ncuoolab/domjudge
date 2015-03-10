
letter		[a-zA-Z_]
identifier	{letter}({letter}|{digit})*
digit           [0-9]
digits          [0-9]*
real            [0-9]*[.][0-9]*
cpy		(cpy)
idcpy		{identifier}_?{cpy}_?({identifier}|{digit})*
cpyletter	{cpy}_?({letter}|{digit})*


%%

{idcpy}		{ ECHO; printf("\n");}
{cpyletter}	{ ECHO; printf("\n");}
. 		{}


%%
int main(int argc, char *argv[]) {
	yylex();
 	return(0);
}

