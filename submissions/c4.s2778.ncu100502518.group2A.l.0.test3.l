%{
int tabcount=0; 
int count=0;
int ture=1;
%}
left	"{"[ |\t]*$
right	\n[ |\t]*"}"[ |\t]*$
tabs	^[\t| ]+
change	\n
word	[^\n{}]+[\t| ]*
%%
{tabs}		{;}
{left}		{ECHO; tabcount++;}
{right}		{tabcount--; printf("\n"); for(count=0;count<tabcount;count++)printf("\t"); printf("}");}
{change}	{ECHO; for(count=0;count<tabcount;count++)printf("\t");}
{word}		{ECHO;}
%%
int main(int argc, char *argv[]) {
	yylex();
	return(0);
}
