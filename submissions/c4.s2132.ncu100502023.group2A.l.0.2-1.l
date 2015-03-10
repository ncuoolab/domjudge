%{
int count = 0;
void tab(int);
%}

left "{"
right "}"
sentence [^" "\t]+

%%

{sentence}{left}.*  {
	tab(count);
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
void tab(int counted) {
	printf("%d", counted);
	while( counted-- > 0 ) {
		printf("\t");
	}
}

int main() {
	yylex();
}