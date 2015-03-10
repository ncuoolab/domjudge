

NAME  [A-Za-z]+
TAB   [ |\t]+
noodlesLine  {NAME}{TAB}{NAME}{TAB}(noodles)+{TAB}{NAME}
word	[\t\n]+

%%

{noodlesLine}  { ECHO; printf("\n"); }
.|\n   {/* do nothing */}
	

%%
int main(int argc, char *argv[]) {
	yylex();
	
	return(0);
}

