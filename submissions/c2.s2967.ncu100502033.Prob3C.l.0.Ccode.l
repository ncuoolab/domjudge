%{
%}
word ^0[Xx][0-9A-Fa-f]{1,6}$
word1 " "0[Xx][0-9A-Fa-f]{1,6}$

%%
{word}	{printf("%s\n",yytext);}
{word1}	{printf("%s\n",1+yytext);}
.	{/*nothing*/}
\n	{/*nothing*/}
%%
main(){
	yylex();
	return(0);
}
