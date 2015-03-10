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
{right}{sentence}.* {
	--count;

	ECHO;
}
. {}

%%
void tab(int counted) {
	while( counted-- > 0 ) {
		printf("\t");
	}
}

int main() {
	yylex();
}