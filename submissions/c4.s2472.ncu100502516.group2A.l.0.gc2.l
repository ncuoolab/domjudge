%{
int count = 0;

%}


word		[a-zA-Z]

%%
("\t")	{}
("{")	{ECHO;count++;}

("}")	{count--;ECHO;}
^{word}	{int i = 0; for(i; i < count; i++){printf("\t");} ECHO;}
^("{")	{int i = 0; for(i; i < count; i++){printf("\t");} ECHO;}
^("}")	{int i = 0; for(i; i < count; i++){printf("\t");} ECHO;}
\n	{int i = 0; for(i; i < count; i++){printf("\t");} ECHO;}

.	{ECHO;}

%%

int main(char *argc)

{
	
	yylex();

	return 0;

}
