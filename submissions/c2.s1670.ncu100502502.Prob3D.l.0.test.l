%{
unsigned int yylval=0 ,  charCount=0, wordCount=0, lineCount=0;

%}
word	--[^ \t\n]+
eol	\n
digit	[0-9]{1}
digit2	[0-9][0-9]
digit3	1[0-9][0-9]|2[0-4][0-9]|25[0-5]
ip	{digit}|{digit2}|{digit3}
ip4	{ip}{point}{ip}{point}{ip}{point}{ip}
ipf	2{ip4}
point	"."
%%
{ip4}	{ECHO; printf("\n");}
{eol}	{}
{word}	{}
{ipf}	{}
.	{}

%%
int main(int argc, char *argv[]) {
	yylex();
	return(0);
}

