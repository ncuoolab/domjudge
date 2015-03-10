Word1 		^[ \t]*[A-Z][a-zA-Z]*$
Word2		^[A-Z][a-zA-Z]*$
IPAddress1	^[ \t]*{IP}"."{IP}"."{IP}"."{IP}$
IPAddress2	^{IP}"."{IP}"."{IP}"."{IP}$
IP		{IP1}|{IP2}|{IP3}|{IP4}|{IP5}
IP1		[1-9][0-9]
IP2		[0-9]
IP3		1[0-9][0-9]
IP4		2[0-4][0-9]
IP5		25[0-5]
EmailAddress1 	^[ \t]*[^ \t\n]+@([a-zA-Z0-9]+".")+[a-zA-Z0-9.]+$
EmailAddress2	^[^ \t\n]+@([a-zA-Z0-9]+".")+[a-zA-Z0-9.]+$
Identifier 	[/][/][a-zA-Z ]+

%%

{Identifier}	{ printf("--%s--\n", yytext+2); }
{Word1}		{ printf("%s is a word\n", yytext+1); }
{Word2}		{ printf("%s is a word\n", yytext); }
{IPAddress1}	{ printf("%s is an IP address\n", yytext+1); }
{IPAddress2}	{ printf("%s is an IP address\n", yytext); }
{EmailAddress1}	{ printf("%s is an email address\n", yytext+1); }
{EmailAddress2}	{ printf("%s is an email address\n", yytext); }
.|\n		{}

%%
 
int main(int argc, char *argv[]) {
	yylex();
	return(0);
}
