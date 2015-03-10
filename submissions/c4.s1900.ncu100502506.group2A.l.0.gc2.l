%x into	
%x second
%x third
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
<into>"{"	{ECHO;BEGIN(second);}
<into>"}"	{ECHO;}
<into>.		{ECHO;}	

<second>^{word}	{printf("\t\t");ECHO;}
<second>^"\t" 	{printf("\t\t");}	
<second>"{"	{ECHO;BEGIN(third);}
<second>"}"	{printf("\t");ECHO;BEGIN(into);}
<second>.	{ECHO;}
<third>^{word} {printf("\t\t\t");ECHO;}
<third>^"\t"   {printf("\t\t\t");}
<third>"}"     {printf("\t\t");ECHO;BEGIN(second);}
<third>.       {ECHO;}

\t		{ECHO;}
.|\n		{ECHO;}

%%
int main(char *argc)
{
	yylex();
	return 0;
}
