%{
%}

word .+noodles.+
%%

{word}	{printf("%s\n",yytext);}
.	{/*nothing*/}
\n	{/*nothing*/}
%%
main(){
	yylex();
	return(0);
}
