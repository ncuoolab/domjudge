Word 		[A-Z][a-zA-Z]*
IPAddress	{IP}"."{IP}"."{IP}"."{IP}$
IP		{IP1}|{IP2}|{IP3}|{IP4}|{IP5}
IP1		[1-9][0-9]
IP2		[0-9]
IP3		1[0-9][0-9]
IP4		2[0-4][0-9]
IP5		25[0-5]
EmailAddress 	^[^ \t\n]+@([a-zA-Z0-9]+".")+[a-zA-Z0-9.]+$
Identifier 	[/][/][a-zA-Z ]+

%%

{Identifier}	{ printf("--%s--\n", yytext+2); }
{Word}		{ ECHO; printf(" is a word\n"); }
{IPAddress}	{ ECHO; printf(" is an IP address\n"); }
{EmailAddress}	{ ECHO; printf(" is an email address\n"); }
.|\n		{}

%%
 
int main(int argc, char *argv[]) {
	yylex();
	return(0);
}
