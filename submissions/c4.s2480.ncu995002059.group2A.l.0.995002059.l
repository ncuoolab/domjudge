%{
unsigned int tab=0,i=0;
%}

left [ \t]*\{
right [ \t]*\}
line [^{left}{right}\n]
eol	\n[ \t]*
tab	\t
special	\n{right}

%%

{left} {tab++; printf("{");}
{right} {tab--;printf("}");}
{tab} {}
{line}	{ECHO;}
{special} {printf("\n"); tab--;for(i=tab;i--;i<1){printf("\t");} printf("}");}
{eol}	{printf("\n");for(i=tab;i--;i<1){printf("\t");}}

%%

int main(int argc , char *argv[]) 
{
	yylex();
	return(0);
}