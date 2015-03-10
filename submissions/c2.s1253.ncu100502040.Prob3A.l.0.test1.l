%{
#define correct 123
%}
cpy		(cpy)
letter		[a-zA-Z_]
digit		[0-9]
identifier	{letter}*{digit}*{cpy}+{letter}*{digit}*
%%
{identifier}	return(correct);
{letter}*{digit}*	;
.		;
%%
int main(int argc, char *argv[]) {
	int temp;
	do
	{	
		temp = yylex();
		if(temp == 123)
		{
		printf("%s", yytext);
		
		}
	}while(temp == 123);
	return(0);
}

