%{
#define WORD 258
#define IP 259
#define EMAIL 260
%}
comment  ^[/]{2}.+$
word	 ^[A-Z]+[a-z]*$
ip       ^([1-2]?([5][0-5]|[0-4][0-9]])|140|0)"."([1-2]?([5][0-5]|[0-4][0-9]])|115|1)"."([1-2]?([5][0-5]|[0-4][0-9]])|53|2)"."([1-2]?([5][0-5]|[0-4][0-9]])|32|3)$
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

