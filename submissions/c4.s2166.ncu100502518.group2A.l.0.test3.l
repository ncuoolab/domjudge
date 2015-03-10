%{
int tabcount=0; 
int count=0;
%}
left	"{"$
right	"}"$
tab	\t
change	\n
word	[^\t\n{}]+
%%
{left}		{ECHO; tabcount++;}
{right}		{ECHO; tabcount--;}
{change}	{ECHO; for(count=0;count<tabcount;count++)printf("\t"); }
{tab}		{;}
{word}		{ECHO;}
%%
int main(int argc, char *argv[]) {
	yylex();
	return(0);
}
