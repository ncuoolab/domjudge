ipAdrs	((25[0-5]|2[0-4][0-9]|[1]?[0-9][0-9]?)\.){3}(25[0-5]|2[0-4][0-9]|[1]?[0-9][0-9]?){1}
dot		\.
nothing	.
%%
{ipAdrs}	ECHO;printf("\n");
{nothing}	;
"\n"		;
%%
int main(int argc, char *argv[])
{
	yylex();
	return(0);
}
