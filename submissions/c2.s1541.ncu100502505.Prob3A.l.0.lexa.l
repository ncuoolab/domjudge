alphabet [A-Z|a-z]
number [0-9]
specha [_|$]


first ^("cpy")({alphabet}|{number}|{specha})*
second ({alphabet}|{specha})*("cpy")({alphabet}|{number}|{specha})*

%%

{first}  {ECHO; printf("\n");}
{second} {ECHO; printf("\n");}
.|\n {}

%%

int main(int argc , char *argv[])
{
	yylex();
	return(0);
}
