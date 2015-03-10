%{
unsigned int tab=0,i=0;
%}

left \{
right [\t]*\}
line [^{left}{right}\n]
eol	\n[ \t]*
tab	\t


%%

{left} {tab++; ECHO;}
{right} {tab--;ECHO;}
{tab} {}
{line}	{ECHO;}
{eol}	{printf("\n");for(i=tab;i--;i<1){printf("\t");}}

%%

int main(int argc , char *argv[]) 
{
	yylex();
	return(0);
}