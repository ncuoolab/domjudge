%{
	int num = 0 ; int i = 0;
%}
word [{]
word1 [}]
value [^\n{}]+ 
%%
{word} {num++;printf("%s",yytext);}
{word1} {num--;	for (i = 0;i<num;i++)
	{printf("\t");}printf("%s",yytext);}
{value} 	{for (i = 0;i<num;i++)
	{printf("\t");}
	
	printf("%s",yytext);}



%%
main(){
	yylex();
	return(0);
}
