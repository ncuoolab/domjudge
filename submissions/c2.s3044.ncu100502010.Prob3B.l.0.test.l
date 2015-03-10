spe[ |\t]+
id [A-Za-z0-9]+
id1 noodles
use {id}{spe}{id}{spe}{id1}{spe}{id}$

%%

{use} {ECHO;} 
.|\n;

%%
int main (int argc, char *argv[]){
	yylex();
	return(0);
}

