%{
unsigned int count = 0;
void print(unsigned int);
%}

left "{"
right "}"
sentence .*\n

%x TAB
%%
{left}\n    {
	ECHO;
    ++count;
	BEGIN TAB;
}

<TAB>{left}{sentence}  {
	print(count);
	++count;
}
<TAB>{right}{sentence}  {
	--count;
	print(count);
	if ( count == 0 ) {
		BEGIN INITIAL;
	}
}

<TAB>{sentence}  {
	print(count);
}
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