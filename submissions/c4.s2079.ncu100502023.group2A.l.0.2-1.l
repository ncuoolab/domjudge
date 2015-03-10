%{
int count = 0;
void tab(int);
%}

left "{"
right "}"
sentence (.)+

%%
(\t|" ")+  {}

{sentence}{left}.*  {
	tab(count);
	ECHO;
	++count;
}
{sentence}{right}.* {
	--count;
	tab(count);
	ECHO;
}
{sentence} {
	tab(count);
	ECHO;
}

. {
ECHO;
printf("d");
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