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



.|\n { ECHO; }

%%

int main() {
	yylex();
}