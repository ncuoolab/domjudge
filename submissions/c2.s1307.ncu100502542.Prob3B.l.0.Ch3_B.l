noodle	[a-zA-Z0-9]*{space}+[a-zA-Z0-9]*{space}+noodles{space}+.*$
space [ \r\n\t]
nothing	.
nextLine	"\n"
%%
{noodle} 	ECHO;printf("\n");
"\t"	;
"\n"	;
{nothing}	;

%%
int main(int argc, char *argv[])
{
	yylex();
	return(0);
}
