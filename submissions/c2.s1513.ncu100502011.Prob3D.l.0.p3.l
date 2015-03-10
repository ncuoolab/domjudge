digits    [0-9]+
%%
{digits}\.{digits}\.{digits}\.{digits}  {ECHO;}
\n             {ECHO;}
.              ;
%%
int main(int argc, char *argv[]) {
	yylex();
	return(0);
}
