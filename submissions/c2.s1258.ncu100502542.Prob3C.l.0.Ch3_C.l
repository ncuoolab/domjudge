hex		^0(x|X)[0-9A-Fa-f]{1,8}$
nothing  .
%%
{hex} 	{ECHO;printf("\n");}
"\n"	;
{nothing}	;

%%
int main(int argc, char *argv[])
{
	yylex();
	return(0);
}
