%{
%}
letter        [a-zA-Z_$]
number        [0-9]+
copy           "cpy"
identifier    {letter}*{copy}({letter}|{number})*
%%
{identifier}  {ECHO;printf("\n");}
.|\n	      {;}
%%
int main(int argc, char *argv[]) {
	yylex();
	return(0);
}
