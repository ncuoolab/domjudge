%{

%}
one [0-9]
two [1-9][0-9]
three [1-2][0-9][0-9]
goal {one}*{two}*{three}*"."{one}*{two}*{three}*"."{one}*{two}*{three}*"."{one}*{two}*{three}*
%%
{goal}	{if(yyleng>=7) ECHO;if(yyleng>=7) printf("\n");}
.|\n	{}
%%
int main(int argc, char *argv[]) {
	yylex();
	return(0);
}