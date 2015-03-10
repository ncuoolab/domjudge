IP ((25[0-5])|(2[0-4][0-9])|(1[0-9][0-9])|([1-9][1-9])|[0-9])
IPa {IP}.{IP}.{IP}.{IP}
%%
{IPa} {ECHO;print("\n");BEGIN ST;}
<ST>"\n"{BEGIN INITIAL;}
.|\n		;
%%
int main(void) {
	yylex();
	return(0);
}
