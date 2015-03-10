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
{space}|{tab}+    { }

^{sentence}{left}(.)*  {
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
}

.|\n { ECHO; }

%%

int main() {
	yylex();
}