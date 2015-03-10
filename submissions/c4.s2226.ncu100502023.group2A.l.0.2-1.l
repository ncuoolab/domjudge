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
tab \t

%%
{tab}+    {
	printf("tab");
}

{space}+ {
	printf("space");
}

^{sentence}{left}(.)*  {
	tab(count);
	ECHO;
	++count;
	printf("left");
}

{right}({sentence})* {
	--count;
	tab(count);
	ECHO;
	printf("right");
}

{sentence} {
	tab(count);
	ECHO;
	printf("sentence");
}

.|\n {
ECHO;
	printf("other");
}

%%

int main() {
	yylex();
}