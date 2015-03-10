%{
	#include <stdio.h>
	#include <string.h>
	unsigned int counter=0;
	int handle(int a)
	{
        	while(a>0)
        	{
                	printf("a\t");
                	a--;
        	}
	}

%}

scope1	^[^\n\t]*"{"$
scope2	^[^\n\t]*"}"$
others	[^\n\t]+
others2	[^\n]+

%%

{scope1}	{handle(counter); counter++; ECHO; printf("s1\n"); printf("%d", counter);}
{scope2}	{counter--; handle(counter); printf("s2%s \n",yytext); }
{others}	{handle(counter); ECHO; printf("o1\n");}
. 
\n	
%%


int main()
{

	yylex();
	return(0);
}
