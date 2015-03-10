%{
unsigned int count=0;
%}
Word		^[A-Z]+([A-Z]|[a-z])*$
IPInteger	(25[0-5]|2[0-4][0-9]|[1-9][0-9]|1[0-9][0-9]|[0-9])
IPAddress	^{IPInteger}\.{IPInteger}\.{IPInteger}\.{IPInteger}$
Email		^[^ \t\n]+@[a-z|0-9]+(\.[a-z|0-9]+)+$
Comment		^"//"([A-Z]|[a-z]|" ")*$
%%
{Word}		{ECHO; printf(" is a word\n");}
{IPAddress}	{ECHO; printf(" is an IP address\n");}
{Email}		{ECHO; printf(" is an email address\n");}
{Comment}	{fprintf(yyout, "--%s--\n", yytext+2);}
.|\n		{}
%%
int main(int argc, char *argv[]){
	yylex();
	return (0);
}
