num [a-f|A-F|0-9]{1,6}
space [\s]+
idx "0x"|"0X"
id1 ^{idx}{num}$
id2 " "{idx}{num}$
%%
 
{id1} {ECHO;printf("\n");} 
{id2} {printf("%s\n",1+yytext);} 
.|\n {}
%%
 
int main(int argc, char *argv[]) {
	yylex();
 	return 0;
}
