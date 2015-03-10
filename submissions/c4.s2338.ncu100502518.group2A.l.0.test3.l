%{
int tabcount=0; 
int count=0;
%}
left1	"{"$
right1	\n"}"$
tab	\t$
change	\n$
word	[^\t\n{}]+$
%%
{left1}		{ECHO; tabcount++;}
{right1}	{tabcount--; printf("\n"); for(count=0;count<tabcount;count++)printf("\t"); printf("}");}
{change}	{ECHO; for(count=0;count<tabcount;count++)printf("\t"); }
{tab}		{;}
{word}		{ECHO;}
%%
int main(int argc, char *argv[]) {
	yylex();
	return(0);
}
