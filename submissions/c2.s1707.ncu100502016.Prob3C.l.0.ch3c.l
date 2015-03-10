%{
%}
word        0[xX][0-9a-fA-F]{1,8}
NotPrint    [^ \t\n]+{word}
NotPrint2   {word}$
%%
{NotPrint}      { }
{NotPrint2}     { }
{word}	   { ECHO; printf("\n"); }
.|\n	  ;
%%
int main(int argc, char *argv[]) {
	yylex();
	return(0);
}

