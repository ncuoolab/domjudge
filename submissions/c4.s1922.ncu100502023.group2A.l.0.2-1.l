%{
unsigned int count = 0;
void print(unsigned int);
%}

left "{"
right "}"
sentence (.)+
space " "
tab   \t

%%
{space}+        {}
(\t)+           {}

^{left}         {
	print(count);
	++count;
}
^{right}         {
	print(count);
	--count;
}
{sentence}{left}.*  {
	print(count);
	++count;
}
{sentence}{right}.* {
	--count;
	print(count);
}
{sentence} {
	print(count);
}

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