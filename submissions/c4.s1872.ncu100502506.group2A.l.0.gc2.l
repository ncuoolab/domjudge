%x into	
%x second
lbracket 	"{"
rbracket	"}"
other		"/"
all		.
test		{lbracket}{all}
word		[a-zA-Z]
%%
"{"		{ECHO;BEGIN(into);}
<into>^{word}	{printf("\t");ECHO;}
<into>^"{"	{printf("\t");ECHO;BEGIN(second);}
<into>"}"	{;ECHO;}
<into>.		{ECHO;}	

<second>^{word}	{printf("\t\t");ECHO;}
<second>^"\t" 	{printf("\t\t");}	
<second>"}"	{printf("\t");ECHO;BEGIN(into);}
<second>.	{ECHO;}
\t		{ECHO;}
.|\n		{ECHO;}

%%
int main(char *argc)
{
	yylex();
	return 0;
}
