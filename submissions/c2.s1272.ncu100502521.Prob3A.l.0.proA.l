%x DECLARE
vaildstart [a-zA-Z_$]
vaildword [a-zA-Z0-9_$]
cpy ['c']['p']['y']
cpyvarible {vaildstart}*{cpy}{vaildword}*
varible {vaildword}+
%%
{cpyvarible} {ECHO;printf("\n");}
.|\n {}
%%
int main(int argc, char *argv[]) {
	yylex();
	return(0);
}
