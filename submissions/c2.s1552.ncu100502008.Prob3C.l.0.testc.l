space \s*
num  [a-f|A-F|0-9]{1,8}
hex ("0x"|"0X"){num}$

%%
{hex} {ECHO;printf("\n");}
.|\n {}

%%
int main(int argc, char *argv[]) {
	yylex();
 	return 0;
}

