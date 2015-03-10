%{
%}
digitEnd ([0-9])|([1-9][0-9])|(1[0-9][0-9])|(2[0-4][0-9])|(25[0-5])
ipp {digitEnd}\.{digitEnd}\.{digitEnd}\.{digitEnd}
%%
{ipp} {printf("%s",yytext);}
. {;}
%%
main(){
	yylex();
	return(0);
}

