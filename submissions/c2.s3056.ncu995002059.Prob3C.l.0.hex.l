%{

%}

left 0[xX]
number [0-9a-fA-F]
right {number}+
hex ^{left}{right}$
spe [ ]{left}{right}$

%%
{hex}	{
	if(yyleng<=10)
		{
		printf("%s\n",yytext);
		}
	}

{spe}	{
	if(yyleng<=11)
		{
		printf("%s\n",yytext+1);
		}
	}

.|\n	{}

%%

int main (int argc , char *argv[])
{
	yylex();
	return(0);
}