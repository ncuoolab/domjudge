%{
int count = 0;
void tab(int counted) {
	while( counted-- > 0 ) {
		printf("\t");
	}
}
%}

left "{"
right "}"
sentence (.)+
space " "

%%
^[ \t]*    {}

{left}({sentence})* {
	tab(count);
	ECHO;
	++count;
}

{sentence}{left}(.)* {
	tab(count);
	ECHO;
	++count;
	printf("dd");
}

{right}({sentence})* {
	--count;
	tab(count);
	ECHO;
}

{sentence} {
	tab(count);
	ECHO;
	printf("ff");
}

.|\n {
	ECHO;
}

%%

int main() {
	yylex();
}