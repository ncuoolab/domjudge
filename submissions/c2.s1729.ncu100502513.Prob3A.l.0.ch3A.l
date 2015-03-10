letter   [a-zA-Z\_\$]*
digit   [0-9]*
validcpy   cpy
identify  {letter}{validcpy}({letter}|{digit})
%%
{identify}  ECHO;printf("\n");
.|\n    ;
%%
int main(int argc, char *argv[]) {
	yylex();	
	return(0);
}

