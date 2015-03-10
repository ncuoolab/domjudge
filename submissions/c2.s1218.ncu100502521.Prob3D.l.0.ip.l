ip [0-1][0-9][0-9]|[2][0-5][0-5]|[0-9]?[0-9]
ipadress {ip}['.']{ip}['.']{ip}['.']{ip}
%%
{ipadress} {ECHO;printf(" is ip adress.\n");}
.|\n {}
%%
int main(int argc, char *argv[] ) {
	yylex();
	return(0);
}
