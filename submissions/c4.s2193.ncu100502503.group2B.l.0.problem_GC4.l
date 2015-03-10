%{
#include <stdio.h>
%}

%x COMMENT
letter		[a-zA-z]+
digit		[0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5]
space		[ \t]+
left		[^ \t\n]+
right		([a-zA-Z]|[0-9])+(["."]([a-zA-Z]|[0-9])+)+
word		[A-Z]{letter}*
ip		{digit}["."]{digit}["."]{digit}["."]{digit}$ 
email		{left}["@"]{right}$
note		{left}[ ]{left}[ ]*{left}*["@"]{right}$
%%
"//"           				{BEGIN COMMENT;}
<COMMENT>{word}({space})*({word})*     	{printf("--");ECHO;printf("--\n");}
<COMMENT>\n   				{BEGIN INITIAL;}
{word}          			{ECHO;printf(" is a word\n");}
{ip}		{ECHO; printf(" is an IP address\n");}
255["."]255["."]255["."]255	{ECHO; printf(" is an IP address\n");}
{email}		{ECHO; printf(" is an email address\n");}
{note}     {/**/}
.|\n		{/**/}
				
%%
int main(int argc,char*argv[]){
        yylex();
        return(0);
}
