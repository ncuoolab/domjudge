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

scope1	^[^\n\t]*"{"[^}\n]*\n
scope2	^[^\n\t]*"}"$
others	[^\n\t]+
others2	[^\n]+
enter	^[\n]

%%

{scope1}	{handle(counter); counter++; ECHO;}
{scope2}	{counter--; handle(counter); printf("%s \n",yytext); }
{others}	{handle(counter); ECHO; printf("\n");}
{enter}		{printf("\n");}
. 
\n	
%%


int main()
{

	yylex();
	return(0);
}
