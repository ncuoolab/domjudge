%{
%}

word [a-zA-z" "]+noodles[a-zA-z" "]+
%%

{word}	{printf("%s\n",yytext);}
.	{/*nothing*/}
\n	{/*nothing*/}
%%
main(){
	yylex();
	return(0);
}
