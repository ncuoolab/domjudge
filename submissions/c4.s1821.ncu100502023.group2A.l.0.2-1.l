%{
unsigned int count = 0;
void print();
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
	print();
	++count;
}
<TAB>{right}{sentence}  {
	--count;
	print();
	if ( count == 0 ) {
		BEGIN INITIAL;
	}
}

<TAB>{sentence}  {
	print();
}
%%

void print() {
	for(int i = 0 ; i < count ; ++i ) {
		printf("\t");
	}
	ECHO;
}

int main() {
	yylex();
}