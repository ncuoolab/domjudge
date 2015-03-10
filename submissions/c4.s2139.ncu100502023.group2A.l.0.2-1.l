%{
int count = 0;
void tab(int counted) {
	printf("%d", counted);
	while( counted-- > 0 ) {
		printf("\t");
	}
}
%}

left "{"
right "}"
sentence [^" "\t]+

%%

{sentence}{left}(.)*  {

	ECHO;
	++count;
}
{right}{sentence} {
	--count;
	tab(count);
	ECHO;
}
.|\n { ECHO; }

%%


int main() {
	yylex();
}