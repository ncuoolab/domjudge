%{
int count=0;
%}
%x into	
lbracket 	"{"
rbracket	"}"
other		"/"
all		.
word		[a-zA-Z]
%%
"{"		{ECHO;count++;BEGIN(into);}
<into>^{word}	{int i=0;for(i;i<count;i++){printf("\t");}ECHO;}
<into>^"\t"	{int i=0;for(i;i<count;i++){printf("\t");}}
<into>^"{"	{int i=0;for(i;i<count;i++){printf("\t");}ECHO;count++;BEGIN(into);}
<into>"{"	{ECHO;count++;BEGIN(into);}
<into>"}"	{int i=0;for(i;i<count-1;i++){printf("\t");}ECHO;count--;}
<into>.		{ECHO;}	

\t		{ECHO;}
.|\n		{ECHO;}

%%
int main(char *argc)
{
	yylex();
	return 0;
}
