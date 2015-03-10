%{
unsigned int count = 0;
void tab(unsigned int);
%}

left "{"
right "}"
sentence (.)+
space " "

%%
{space}+        {}
(\t)+           {}



%%

void tab(unsigned int counted) {
	while( counted-- > 0 ) {
		printf("\t");
		printf("%d", counted);
	}
}

int main() {
	yylex();
}