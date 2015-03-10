
wordtable	"//"Word
IPtable		"//"IP" "Address
emailtable	"//"Email" "Address
word		[A-Z][A-Za-z]*
int		([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])
IP		{int}\.{int}\.{int}\.{int}
string		[^ \t\n\.]+
email		[^ \t\n]+@({string}\.)+{string}
%%

{wordtable}	{ printf("--Word--\n"); }
{IPtable}	{ printf("--IP Address--\n"); }
{emailtable}	{ printf("--Email Address--\n"); }
{word}		{ ECHO; printf(" is a word\n");}
{IP}		{ ECHO; printf(" is an IP address\n");}
{email}		{ ECHO; printf(" is an email address\n");}
.|\n		;

%%
int main(int argc, char *argv[]) {
	yylex();
 	return(0);
}

