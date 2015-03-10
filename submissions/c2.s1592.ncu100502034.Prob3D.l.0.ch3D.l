%{
%}
digit ([0-9].)|([0-9][0-9].)|([0-9][0-9][0-9].)
digitEnd ([0-9])|([0-9][0-9])|([0-9][0-9][0-9])
ipp {digit}{digit}{digit}{digitEnd}
%%
{ipp} {printf("%s",yytext);}
.|\n {ECHO;}
%%
main(){
	yylex();
}
