space [\s]+
num [a-f|A-F|0-9]{1,6}
x "0x"|"0X" 
hex ^{x}{num}$
hex2 " "{x}{num}$

%%
{hex} {ECHO;printf("\n");}
{hex2} {printf("%s\n",1+yytext);}
.|\n {}
%%

int main(int argc, char *argv[]) {
	yylex();
 	return 0;
}
