%{
int count = 0;
void tab(int);
%}

left "{"
right "}"
sentence (.)+

%%
(\t|" ")+  {}


%%
void tab(int counted) {
	while( counted-- > 0 ) {
		printf("\t");
	}
}

int main() {
	yylex();
}