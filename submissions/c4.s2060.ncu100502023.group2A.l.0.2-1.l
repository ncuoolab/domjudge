%{
int count = 1;
void tab(int);
%}

left "{"
right "}"
sentence (.)+
space " "

%%

{sentence}{left}.*  {
	tab(count);
	ECHO;
	++count;
}
{sentence}{right}.* {
	--count;
	tab(count);
	ECHO;
}
{sentence} {
	tab(count);
	ECHO;
}


%%
void tab(int counted) {
	while( counted-- > 0 ) {
		printf("\t");
		printf("%d", counted);
	}
}

int main() {
	yylex();
}