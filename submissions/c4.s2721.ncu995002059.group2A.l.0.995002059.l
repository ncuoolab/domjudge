%{
unsigned int tab=0,i=0;
%}

left \{
right [ \t]*\}
line [^{left}{right}{tab}\n]
eol	\n[ \t]*
tab	\t


%%
{eol}	{printf("\n");for(i=tab;i--;i<1){printf("\t");}}
{left} {tab++; printf("{");}
{right} {tab--;ECHO;}
{tab} {}
{line}	{ECHO;}

%%

int main(int argc , char *argv[]) 
{
	yylex();
	return(0);
}