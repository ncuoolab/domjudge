%{
%}
word ^.+[ \t]+.+[ \t]+noodles[ \t]+.+$
wordd N.*
%%
{wordd} ;
{word} {printf("%s\n",yytext);}
.|\n ;
%%
main(){
	yylex();
	return(0);
}
