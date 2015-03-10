%{
int tabcount=0; 
int count=0;
%}
left	[ |\t]*"{"[ |\t]*$
right	\n[ |\t]*"}"[ |\t]*$
tab		\t
change	\n
word	[^\t\n{}]+
space	" "+$
%%
{left}		{ECHO; tabcount++;}
{right}	{tabcount--; printf("\n"); for(count=0;count<tabcount;count++)printf("\t"); printf("}");}
{change}	{ECHO; for(count=0;count<tabcount;count++)printf("\t"); }
{tab}		{;}
{word}		{ECHO;}
{space}		{;}
%%
int main(int argc, char *argv[]) {
	yylex();
	return(0);
}
