%{
#define Word 258
#define IP_Address 259
#define Email_Address 260
%}
%x COMMENT
Word		 ^[A-Z][a-zA-Z]*
str		[a-zA-Z0-9]+
n1              [0-9]
n2              [1-9][0-9]
n3              1[0-9][0-9]
n4              2[0-4][0-9]
n5              25[0-5]
num             {n1}|{n2}|{n3}|{n4}|{n5}
IP_Address	^{num}\.{num}\.{num}\.{num}$
s		\.{str}
Email_Address	^[^ \t\n]+"@"{str}{s}+$
%%
"//"            { BEGIN COMMENT; printf("--"); }
<COMMENT>.      { ECHO; }
<COMMENT>\n     { printf("--\n"); BEGIN INITIAL; }
{Word}		{ ECHO; printf(" is a word\n"); }
{IP_Address}	{ ECHO; printf(" is an IP address\n"); }
{Email_Address}	{ ECHO; printf(" is an email address\n"); }
.|\n		{}
%%
int main(int argc, char *argv[]) {
	yylex();
	return(0);
}
