

letter		[a-zA-Z_]
letters		[a-zA-Z_]*
identifier	{letter}({letter}|{digit})*
digit           [0-9]
digits          [0-9]*
real            [0-9]*[.][0-9]*
noodles		(noodles)
eol		\n
word		[^ \t\n]
st		[ ]*[\t]*[ ]*


%%
({letters}|{digits})*{st}*({letters}|{digits})*{st}*{noodles}{st}*({letters}|{digits})*	{ECHO;}
.											{}

%%
int main(int argc, char *argv[]) {
	yylex();
 	return(0);
}

