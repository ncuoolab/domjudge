%{
#define WORD 258
#define IP 259
#define EMAIL 260
%}
comment  ^[/]{2}.+$
word	 ^[A-Z]+[a-z]*$
segement   ([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])
ip       ^{segement}"."{segement}"."{segement}"."{segement}$
Email 	 ^[^ \t\n@]+@(.+"."){1,}.+$
%%
{comment}  { printf("--"); printf("%s",2+yytext); printf("--\n"); }
{word}	   { ECHO; printf(" is a word\n"); }
{ip}	   { ECHO; printf(" is an IP address\n"); }
{Email}	   { ECHO; printf(" is an email address\n"); }
.|\n	;
%%
int main(int argc, char *argv[]) {
	yylex();
	return(0);
}

