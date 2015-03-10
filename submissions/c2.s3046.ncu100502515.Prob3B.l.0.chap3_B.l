%{
%}
word	  [a-zA-Z]+
space	  [ ]+
noodles   "noodles"
output 	  {word}{space}{word}{space}{noodles}{space}{word}
%%
{output}  {ECHO;printf("\n");}
.|\n	  {;}
%%
int main(int argc, char *argv[]) {
	yylex();
	return(0);
}
