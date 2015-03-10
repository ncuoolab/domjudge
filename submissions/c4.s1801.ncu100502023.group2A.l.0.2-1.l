%{
unsigned int count = 0;
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
	for(int i = 0 ; i < count ; ++i ) {
		printf("\t");
	}
	ECHO;
	++count;
}
<TAB>{right}{sentence}  {
	--count;
	for(int i = 0 ; i < count ; ++i ) {
		printf("\t");
	}
	ECHO;
	if ( count == 0 ) {
		BEGIN INITIAL;
	}
}

<TAB>{sentence}  {
	for(int i = 0 ; i < count ; ++i ) {
		printf("\t");
	}
	ECHO;
}

%%

int main() {
	yylex();
}