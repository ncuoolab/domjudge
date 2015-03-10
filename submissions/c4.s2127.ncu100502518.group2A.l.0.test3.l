%{
unsigned int tabcount=0;
%}
left	"{"$
right	"}"$
tab	\t
change	\n
word	[^\t\n{}]+
%%
{left}		{ECHO; tabcount++;}
{right}		{ECHO; tabcount--;}
{change}	{ECHO; printf("\t"); }
{tab}		{;}
{word}		{ECHO;}
%%
int main(int argc, char *argv[]) {
	for(int i=0;i<tabcount;i++) {
		yylex();
	}
	return(0);
}
