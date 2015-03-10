
ncpy		[0-9][a-zA-Z_$0-9]*cpy[a-zA-z_$0-9]*
cpy		([[a-zA-Z_$][a-zA-Z_$0-9]*cpy]|cpy)[a-zA-z_$0-9]*
%%
{ncpy}		;
{cpy}		{ ECHO; printf("\n") ; }
.|\n		;
%%
int main(int argc, char *argv[]) {
	yylex();
 	return(0);
}


