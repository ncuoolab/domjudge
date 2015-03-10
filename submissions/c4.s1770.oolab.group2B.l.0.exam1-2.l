%{
#include <string.h>
#include <stdlib.h>
#define LETTERS 258
#define IP 259
#define EMAIL 260

%}
%x COMMENT
%%
[a-z][A-Z][a-zA-Z]* {}
[A-Z][a-zA-Z]*	{printf("%s is a word\n", yytext); return (LETTERS);}
^(([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])\.){3}([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])$	{printf("%s is an IP address\n", yytext); return (IP);}
^([0-9a-z]+[-._+&])*[0-9a-z]+@([0-9a-z]+[.])+[a-z]{2,3}$	{printf("%s is an email address\n", yytext); return (EMAIL);}
"//"		{printf("--"); BEGIN COMMENT;}
<COMMENT>.	{printf("%s", yytext);}
<COMMENT>\n	{printf("--\n"); BEGIN INITIAL;}
.|\n		{/*Do nothing*/}
%%
int main(int argc, char *argv[]) {
	while(yylex());
	return(0);
}

