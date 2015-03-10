%{
%}
word ^.+[ \t]*.+[ \t]*noodles[ \t]*.+$

%%
{word} {printf("%s\n",yytext);}
.|\n ;
%%
main(){
	yylex();
	return(0);
}
