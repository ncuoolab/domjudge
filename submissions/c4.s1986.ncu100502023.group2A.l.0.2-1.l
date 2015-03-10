%{
unsigned int count = 0;
void tab(unsigned int);
%}

left "{"
right "}"
sentence (.)+
space " "

%x REPLCAE

%%

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

%%

void tab(unsigned int counted) {
	while( counted-- > 0 ) {
		printf("\t");
	}
}

int main() {
	yylex();
}