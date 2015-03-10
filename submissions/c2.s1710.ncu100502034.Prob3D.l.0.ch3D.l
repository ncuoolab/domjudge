%{
%}
digitEnd ([0-9])|([0-9][0-9])|([0-9][0-9][0-9])
ipp {digitEnd}\.{digitEnd}\.{digitEnd}\.{digitEnd}
%%
{ipp} {printf("%s",yytext);}
. {;}
%%
main(){
	yylex();
	return(0);
}

