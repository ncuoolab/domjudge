%{
int tabcount=0; 
int count=0;
%}
left	"{"$
right	\n"}"$
tab	\t
change	\n
word	[^\t\n{}]+
%%
{left}		{ECHO; tabcount++;}
{right}		{ECHO; tabcount--; for(count=0;count<tabcount;count++)printf("\t");}
{change}	{ECHO; for(count=0;count<tabcount;count++)printf("\t"); }
{tab}		{;}
{word}		{ECHO;}
%%
int main(int argc, char *argv[]) {
	yylex();
	return(0);
}
