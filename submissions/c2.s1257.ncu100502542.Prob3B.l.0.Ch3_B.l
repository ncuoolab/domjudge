noodle	.*noodles.*
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
