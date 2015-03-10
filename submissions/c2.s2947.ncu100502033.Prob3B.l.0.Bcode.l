%{
%}

word ^[a-zA-Z]+[ \t]+[a-zA-Z]+[ \t]+noodles[ \t+][a-zA-Z]+
%%

{word}	{printf("%s\n",yytext);}
.	{/*nothing*/}
\n	{/*nothing*/}
%%
main(){
	yylex();
	return(0);
}
