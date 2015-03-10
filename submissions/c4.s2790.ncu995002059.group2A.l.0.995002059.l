%{
unsigned int tab=0,i=0;
%}

left \{
right [ \t]*\}[ \t]*
line [^{left}{right}{tab}\n]
eol	\n[ \t]*
tab	\t
special	\n{right}

%%
{eol}	{printf("\n");for(i=tab;i--;i<1){printf("\t");}}
{left} {tab++; printf("{");}
{right} {tab--;ECHO;}
{tab} {}
{line}	{ECHO;}
{special} {printf("\n"); tab--;for(i=tab;i--;i<1){printf("\t");} printf("}");}
%%

int main(int argc , char *argv[]) 
{
	yylex();
	return(0);
}