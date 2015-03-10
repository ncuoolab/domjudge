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

[^ \t]+{sentence} {
	tab(count);
	ECHO;
}

\t|" "  {}

.|\n {
ECHO;
}

%%

int main() {
	yylex();
}