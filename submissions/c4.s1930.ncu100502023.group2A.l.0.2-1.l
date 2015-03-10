%{
unsigned int count = 0;
void print(unsigned int);
%}

left "{"
right "}"
sentence (.)*
space " "

%%
{space}+        {}
(\t)+           {}



.    { ECHO; }
%%

void print(unsigned int counted) {
	while(counted-- > 0) {
		printf("\t");
	}
	ECHO;
}

int main() {
	yylex();
}