%{
%}
word        0[xX][0-9a-fA-F]{1,8}$

NotPrint    [^ \t\n]+0[xX][0-9a-fA-F]{1,8}
%%
{NotPrint}  ;
{word}	   { ECHO; printf("\n"); }
.|\n	  ;
%%
int main(int argc, char *argv[]) {
	yylex();
	return(0);
}

