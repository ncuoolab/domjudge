%{
#include <stdio.h>
#include <stdlib.h>
#define Word 258
#define IP_Address 259
#define Email_Address 260
%}
%x COMMENT
AZ		[A-Z]
az		[a-z]

str		[a-zA-Z0-9]+
Word		[A-Z]({AZ}|{az})*
Word2		[ |\t][A-Z][a-zA-Z]*
n1		[0-9]
n2		[1-9][0-9]
n3		1[0-9][0-9]
n4		2[0-4][0-9]
n5		25[0-5]
num		{n1}|{n2}|{n3}|{n4}|{n5}
IP_Address	^{num}\.{num}\.{num}\.{num}$
add2		[ |\t]{num}\.{num}\.{num}\.{num}$
s		\.{str}
Email_Address	^[^ \n\t]+"@"{str}{s}+$
group		"//"[a-zA-Z0-9 ]+
%%
"//"            { BEGIN COMMENT; printf("--"); }
<COMMENT>.      { ECHO; }
<COMMENT>\n     { printf("--\n"); BEGIN INITIAL; }
{Word}		{ ECHO; printf(" is a word\n"); }
{Word2}		{ printf("%s is a word\n",yytext+1); }
{IP_Address}	{ ECHO; printf(" is an IP address\n"); }
{add2}		{ printf("%s is an IP address\n",yytext+1); }
{Email_Address}	{ ECHO; printf(" is an email address\n"); }
.|\n		{}
%%
int main(int argc, char *argv[]) {
	yylex();
	return(0);
}
