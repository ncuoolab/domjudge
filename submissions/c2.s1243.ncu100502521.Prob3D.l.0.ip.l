ip [1][0-9][0-9]|[2][0-4][0-9]|[2][5][0-5]|[1-9][0-9]|[0-9]
ipadress {ip}['.']{ip}['.']{ip}['.']{ip}
%%
{ipadress} {ECHO;printf("\n");}
.|\n {}
%%
int main(int argc, char *argv[] ) {
	yylex();
	return(0);
}
