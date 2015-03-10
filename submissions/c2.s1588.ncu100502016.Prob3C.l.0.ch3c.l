%{
%}
word        0[xX][0-9a-fA-F]{1,8}
NotPrint    [^ \t]+{word}
NotPrint2   {word}[^ \t]+
NotPrint3   [^ \t]+{word}[^ \t]+
%%
{NotPrint}      ;
{NotPrint2}     ;
{NotPrint3}     ;
{word}	   { ECHO; printf("\n"); }
.|\n	  ;
%%
int main(int argc, char *argv[]) {
	yylex();
	return(0);
}

