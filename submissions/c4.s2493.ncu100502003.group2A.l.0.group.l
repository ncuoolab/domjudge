%{
	#include <stdio.h>
	#include <string.h>
	unsigned int counter=0;
	int handle(int a)
	{
        	while(a>0)
        	{
                	printf("\t");
                	a--;
        	}
	}

%}

scope1	^[^{}\n\t]*"{"
scope2	^[^{}\n\t]*"}"
others	[^\n\t]+
others2	[^\n\t]+

%%

{scope1}	{handle(counter); ECHO; printf("\n"); counter++;}
{scope2}	{counter--; handle(counter); printf("%s \n",yytext);}
{others}	{handle(counter); ECHO; printf("\n");}

. 
\n	
%%


int main()
{

	yylex();
	return(0);
}
