%{

%}
hexhead		(0x|0X)
digit		[0-9a-fA-F]
digits		{digit}{1,8}
hex		^{hexhead}{digits}\n

%% 
{hex}		{printf("%s", yytext);}
.|\n		{}
%%
int main(int argc, 
char *argv[]) {
	yylex();
 	return(0);
}
