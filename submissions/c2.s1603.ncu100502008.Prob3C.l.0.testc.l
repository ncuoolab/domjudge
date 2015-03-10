al [a-f|A-F]
d [0-9]
x "0x"|"0X" 
hex ^{x}({al}|{d}){1,6}\n

%%
{hex} {ECHO;}
.|\n {}

%%
int main(int argc, char *argv[]) {
	yylex();
 	return 0;
}
