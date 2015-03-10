%{
int tabcount=0; 
int count=0;
int ture=1;
%}
left	"{"[ |\t]*$
right	"}"[ |\t]*$
tabs	^[\t| ]+
change	\n
word	[^\t\n{}]+\t*
%%
{tabs}		{;}
{left}		{ECHO; tabcount++;}
{right}		{tabcount--; ECHO;}
{change}	{ECHO; for(count=0;count<tabcount;count++)printf("\t");}
{word}		{ECHO;}
%%
int main(int argc, char *argv[]) {
	yylex();
	return(0);
}
