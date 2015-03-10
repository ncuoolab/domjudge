%{
unsigned int tabcount=0;
%}
left	"{"$
right	"}"$
tab	\t
change	\n
word	[^\t\n{}]+
%%
{left}		{ ECHO; tabcount++; }
{right}		{ ECHO; tabcount--; }
{change}	{ printf(\t{tabcount}); ECHO; }
{tab}		{;}
{word}		{ ECHO; }
%%
int main(int argc, char *argv[]) {
	yylex();
	return(0);
}
