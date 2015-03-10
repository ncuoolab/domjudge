%{
#define correct 123
%}
cpy		(cpy)
letter		[a-zA-Z_]
digit		[0-9]
space		[ ]
identifier	{letter}*{cpy}+{letter}*{digit}*
%%
{letter}*{cpy}	;
{identifier}	{ECHO; printf("\n");}
\n		;
.		;
%%
int main(int argc, char *argv[]) {
        yylex();
	return(0);
}

