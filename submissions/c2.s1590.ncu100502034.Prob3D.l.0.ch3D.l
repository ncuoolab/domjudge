%{
%}
digit ([0-9].)|([0-9][0-9].)|([0-9][0-9][0-9].)
digitEnd ([0-9])|([0-9][0-9])|([0-9][0-9][0-9])
ipp {digit}{digit}{digit}{digitEnd}
%%
{ipp} {printf("get %s",yytext);}
.|\n {ECHO;}
%%
main(){
	yylex();
}
