%{
%}
digitEnd ([0-9])|([1-9][0-9])|(1[0-9][0-9])|(2[0-4][0-9])|(25[0-5])
ipp {digitEnd}\.{digitEnd}\.{digitEnd}\.{digitEnd} 
error (25[6-9])|(2[6-9][0-9)])|([3-9][0-9][0-9])|([1-9][0-9][0-9][0-9]+) 
errorrip {error}\.{error}\.{error}\.{error}
word ([a-z|A-Z])
ipAress \/\/IP[ ]Address
emailAress \/\/Email[ ]Address
email [^ \t\n]*@.*\..*
%% 
{email} {printf("%s is an email address\n",yytext);}
{ipAress} {printf("--IP Address--\n");}
{emailAress} {printf("--Email Address--\n");}
\/\/Word {printf("--Word--\n");}
{error} {/*nothing*/}
{ipp}(\.)|([0-9]*) {;}
{ipp} {printf("%s is a IP address\n",yytext);}
{word}* {printf("%s is a word\n",yytext);}
.|\n {;}
%%
main(){
	yylex();
	return(0);
}
