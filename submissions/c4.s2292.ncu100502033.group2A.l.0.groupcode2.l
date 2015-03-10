%{
	int num = 0 ; int i = 0;
%}
word [{]
word1 [}]
%%
{word} {num++;printf("%s",yytext);}
{word1} {num--;printf("%s",yytext);}
\n	{printf("\n");
	for (i = 0;i<num;i++)
		{printf("\t");}
	}

%%
main(){
	yylex();
	return(0);
}
