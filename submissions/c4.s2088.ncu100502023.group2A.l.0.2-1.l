%{
int count = 0;
void tab(int);
%}

left "{"
right "}"
sentence (.)+

%%

{sentence}{left}.*  {

	ECHO;
	++count;
}
{sentence}{right}.* {
	--count;

	ECHO;
}
{sentence} {

	ECHO;
}

%%
void tab(int counted) {
	while( counted-- > 0 ) {
		printf("\t");
	}
}

int main() {
	yylex();
}