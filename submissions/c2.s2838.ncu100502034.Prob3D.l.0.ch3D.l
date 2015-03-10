number ([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])
aR {number}\.{number}\.{number}\.{number}
aRNo [\.]{aR}
test -[.]*
%%
{aRNo} ;
{aR} {ECHO; printf("\n");}
{test} ;
.|\n ;
%%
int main(){
	yylex();
	return(0);
}
