%{
%}
digitEnd ([0-9])|([1-9][0-9])|(1[0-9][0-9])|(2[0-4][0-9])|(25[0-5])
ipp {digitEnd}\.{digitEnd}\.{digitEnd}\.{digitEnd}
error (25[6-9])|(2[6-9][0-9)])|([3-9][0-9][0-9])|([1-9][0-9][0-9][0-9]+)
%%
{error} {/*nothing*/}
{ipp} {printf("%s\n",yytext);}
{ipp}+ {}
.|\n {}
%%
main(){
	yylex();
	return(0);
}

