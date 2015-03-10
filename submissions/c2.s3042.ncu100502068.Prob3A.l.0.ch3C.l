%{

%}
hexhead		(0x|0X)
digit		[0-9a-fA-F]
digits		{digit}{1,8}
blank		" "
hex		{hexhead}{digits}\n
hex2		{blank}{hex}

%%
^{hex}		{printf("%s", yytext);}
{hex2}          {printf("%s", 1+yytext);}
.|\n		{}
%%
int main(int argc, 
char *argv[]) {
	yylex();
 	return(0);
}
