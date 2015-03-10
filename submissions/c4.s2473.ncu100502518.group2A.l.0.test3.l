%{
int tabcount=0; 
int count=0;
%}
left1	[ |\t]*"{"[ |\t]*$
right1	\n[ |\t]*"}"[ |\t]*$
tab		\t
change	\n
word	[^\t\n{}]+
space	" "+$
%%
{left1}		{ECHO; tabcount++;}
{right1}	{tabcount--; printf("\n"); for(count=0;count<tabcount;count++)printf("\t"); printf("}");}
{change}	{ECHO; for(count=0;count<tabcount;count++)printf("\t"); }
{tab}		{;}
{word}		{ECHO;}
{space}		{for(count=0;count<tabcount;count++)printf("\t");}
%%
int main(int argc, char *argv[]) {
	yylex();
	return(0);
}
