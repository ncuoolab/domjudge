out [0-9][a-zA-Z_$]*(cpy)[a-zA-Z0-9_$]*
right [a-zA-z_$]*(cpy)[a-zA-Z0-9_$]*
eol \n
%%
{out} ;
{right} {ECHO; printf( "\n");}
.|\n ;

%%

int main(int argc, char *argv[]){
	yylex();
	return(0);

}

