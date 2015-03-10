%{
unsigned int count = 0;
void print(unsigned int);
%}

left "{"
right "}"
sentence .*

%x TAB

%%
{left}\n    {
	ECHO;
    ++count;
	BEGIN TAB;
}

<TAB>{sentence}{left}.*  {
	print(count);
	++count;
}
<TAB>{sentence}{right}.* {
	--count;
	print(count);
	if ( count == 0 ) {
		BEGIN INITIAL;
	}
}
<TAB>{sentence} {
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