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
sentence [^ \t](.)+
space " "

%%
^[ \t]*    {}

{left}(.)* {
	tab(count);
	ECHO;
	++count;
}

{sentence}{left}(.)* {
	tab(count);
	ECHO;
	++count;
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
	printf("dd");
}

%%

int main() {
	yylex();
}