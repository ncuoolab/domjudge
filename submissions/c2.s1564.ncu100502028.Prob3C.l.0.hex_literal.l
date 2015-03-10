head	0(x|X)
digit   [0-9] 
letter  [a-fA-F]
hex     ^{head}({digit}|{letter}){1,8}$
hex2     " "{head}({digit}|{letter}){1,8}
%%
{hex}   { ECHO; printf("\n"); }
{hex2}   { printf("%s",1+yytext); printf("\n"); }
.|\n    ;
%%
int main(int argc, char *argv[]) {
	yylex();
	return(0);
}

