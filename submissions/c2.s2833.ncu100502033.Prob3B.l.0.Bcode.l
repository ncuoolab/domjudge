%{
%}
word .+noodles.+
%%
{word} {printf("%s",yytext);}
.	{/*nothing*/}
%%
main(){
	yylex();
	return(0);
}
