%{
unsigned int count = 0;
void tab(unsigned int);
%}

left "{"
right "}"
sentence (.)+
space " "

%x REPLCAE

%%
<REPLCAE>(\t|{space})+    {
	BEGIN INITIAL;
}

{sentence}{left}.*  {
	BEGIN REPLCAE;
	tab(count);
	ECHO;
	++count;
}
{sentence}{right}.* {
	BEGIN REPLCAE;
	--count;
	tab(count);
	ECHO;
}
{sentence} {
	BEGIN REPLCAE;
	tab(count);
	ECHO;
}


%%
void tab(unsigned int counted) {
	while( counted-- > 0 ) {
		printf("\t");
	}
}

int main() {
	yylex();
}