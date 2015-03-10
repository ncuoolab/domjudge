%{

%}
key		cpy
letter		[a-zA-Z]
digit		[0-9]
special		_|$
char		{letter}|{digit}|{special}
id		{letter}{char}*{key}{char}*|{key}{char}*

%%
{id}		{printf("%s\n",yytext);}
.|\n		{}
%%
int main(int argc, char *argv[]) {
	yylex();
	return(0);
}
