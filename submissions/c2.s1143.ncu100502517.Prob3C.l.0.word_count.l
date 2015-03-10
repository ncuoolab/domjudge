hexdigit	[0-9a-fA-F]{1,8}
check		^(0x|0X){hexdigit}+
%%
{check}	{ECHO;printf("\n");}
.|\n	{/*do nothing*/}
%%
int main(int argc, char *argv[]) {
	yylex();
	return(0);
}

