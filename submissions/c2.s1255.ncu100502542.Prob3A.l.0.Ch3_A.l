ntoken	[0-9]cpy
token [a-zA-Z_\$]*cpy[\$_a-zA-Z0-9]*
nothing .
%%
{ntoken}	;
{token}	{ECHO;printf("\n");}
"\n"	;
{nothing} ;
%%
int main(int argc, char *argv[])
{
	yylex();
	return(0);
}
