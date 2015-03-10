%{
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

scope1	^[^{}\n]*"{"
scope2	^[^{}\n]*"}"
others	[^\n]+
space2	^[\t]+{others}

%%


{scope1}	{handle(counter); ECHO; printf("\n"); counter++;}
{scope2}	{counter--; handle(counter); printf("%s \n",yytext);}
{space2}	{handle(counter-1); ECHO; printf("\n");}
{others}	{handle(counter); ECHO; printf("\n");}
. 
\n	
%%


int main()
{

	yylex();
	return(0);
}
