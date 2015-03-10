%{
unsigned int tabcount=0; i=0;
%}
left	"{"$
right	"}"$
tab	\t
change	\n
word	[^\t\n{}]+
%%
{left}		{ECHO; tabcount++;}
{right}		{ECHO; tabcount--;}
{change}	{ECHO; for(i=0;i<tabcount;i++)printf("\t"); }
{tab}		{;}
{word}		{ECHO;}
%%
int main(int argc, char *argv[]) {
	yylex();
	return(0);
}
