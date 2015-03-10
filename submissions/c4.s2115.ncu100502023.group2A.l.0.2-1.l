%{
int count = 0;
void tab(int);
%}

left "{"
right "}"
tab \t
space " "
sentence [^" "\t]+

%%
{tab}    {}
{space}  {}

({sentence})*{left}.*  {
	tab(count);
	ECHO;
	++count;
}
{right}({sentence})*.* {
	--count;

	ECHO;
}
. { ECHO; }

%%
void tab(int counted) {
	while( counted-- > 0 ) {
		printf("\t");
	}
}

int main() {
	yylex();
}