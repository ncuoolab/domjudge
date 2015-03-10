cpy     [a-zA-Z_$]*cpy[a-zA-Z_$0-9]*
cpy_ex  [0-9]+cpy[a-zA-Z_$0-9]*
%%

{cpy_ex}   ;

{cpy}      { ECHO; printf("\n"); }

.|\n    ;

%%

int main(int argc, char *argv[]) {
	
	yylex();
	
	return(0);

}
