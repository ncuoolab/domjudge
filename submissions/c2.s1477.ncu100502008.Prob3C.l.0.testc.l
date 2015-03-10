hex ^("0x"|"0X")[a-f|A-F|0-9]+$

%%

{hex} {ECHO;printf("\n");}
.|\n {}

%%
int main(int argc, char *argv[]) {
	yylex();
 	return(0);
}

