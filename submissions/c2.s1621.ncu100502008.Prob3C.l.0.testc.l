
space [" "]*
num [a-f|A-F|0-9]{1,6}
x "0x"|"0X" 
hex ^{space}{x}{num}\n

%%
{hex} {ECHO;}
.|\n {}

%%
int main(int argc, char *argv[]) {
	yylex();
 	return 0;
}
