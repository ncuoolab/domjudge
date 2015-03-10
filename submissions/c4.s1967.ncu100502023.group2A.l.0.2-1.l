%{
unsigned int count = 0;
void print(unsigned int);
%}

left "{"
right "}"
sentence (.)+
space " "

%%
{space}+        {}
(\t)+           {}

{sentence}{left}.*  {
	print(count);
	++count;
	ECHO;
}
{sentence}{right}.* {
	--count;
	print(count);
	ECHO;
}
{sentence} {
	print(count);
	ECHO;
}

.          { ECHO; }
%%

void print(unsigned int counted) {
	while( counted-- > 0 ) {
		printf("\t");
		printf("%d", counted);
	}
}

int main() {
	yylex();
}