%{
int count = 0;
void tab(int counted) {
	printf("%d", counted);
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
{space}+    { printf("\n") };
{tab}+      { }

{sentence} {
	tab(count);
	ECHO;
}

.|\n { ECHO; }

%%


int main() {
	yylex();
}