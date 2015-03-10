word	--[^ \t\n]+
eol	\n
digit	[0-9]{1}
digit2	[0-9][0-9]
digit3	1[0-9][0-9]|2[0-4][0-9]|25[0-5]
ip	{digit}|{digit2}|{digit3}
ip4	^{ip}{point}{ip}{point}{ip}{point}{ip}
point	"."
%%
{ip4}	{ECHO; printf("\n");}
{eol}	{}
{word}	{}
.	{}

%%
int main(int argc, char *argv[]) {
	yylex();
	return(0);
}

