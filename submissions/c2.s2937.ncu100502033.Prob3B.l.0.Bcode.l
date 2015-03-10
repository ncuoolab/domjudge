%{
%}

word ^[a-zA-z]+[ \t]+[a-zA-z]+[ \t]+noodles[ \t+][a-zA-z]+
%%

{word}	{printf("%s\n",yytext);}
.	{/*nothing*/}
\n	{/*nothing*/}
%%
main(){
	yylex();
	return(0);
}
