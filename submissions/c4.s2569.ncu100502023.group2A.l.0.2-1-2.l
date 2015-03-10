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

%x CLEAN

%%
<CLEAN>" " { }
<CLEAN>.   { ECHO; }
<CLEAN>\n  { BEGIN INITIAL;}

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

[ \t]+{sentence} {
	tab(count);
	BEGIN CLEAN;
}

{sentence} {
	tab(count);
	ECHO;
}

.|\n {
ECHO;
}

%%

int main() {
	yylex();
}