%{
%}
digitEnd ([0-9])|([1-9][0-9])|(1[0-9][0-9])|(2[0-4][0-9])|(25[0-5])
ipp {digitEnd}\.{digitEnd}\.{digitEnd}\.{digitEnd}
error (25[6-9])|(2[6-9][0-9)])|([3-9][0-9][0-9])|([1-9][0-9][0-9][0-9]+) 
errorrip {error}\.{error}\.{error}\.{error}
word [a-z]|[A-Z]
wordErr (^{word}|@)|[ ]
ipAress \/\/IP[ ]Address
emailAress \/\/Email[ ]Address 
email [^ \t\n]*@.*\..*
emailErr [ ]{email}
iperr {digitEnd}\.{digitEnd}\.{digitEnd}\.[0-9][0-9][0-9][0-9]+
%%
{emailErr} {;}
\n{email} {printf("%s is an email address",yytext);}
{ipAress} {printf("--IP Address--\n");} 
{emailAress} {printf("--Email Address--");}
\/\/Word {printf("--Word--\n");}
{error} {;}
{iperr} {;}
{ipp} {printf("%s is an IP address\n",yytext);} 
{word}+{wordErr}+ {;}
[A-Z]{word}* {printf("%s is a word\n",yytext);}
.|\n {;}
%%
main(){
	yylex();
	printf("\n");
	return(0);
}
