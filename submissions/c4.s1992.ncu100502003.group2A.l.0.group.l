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

scope1	[^{}\n]*"{"
scope2	[^{}\n]*"}"
others	[^\n]+
space	^[ \t]+

%%
{space}		{}
{scope1}	{handle(counter); printf("%s \n",yytext);counter++;}
{scope2}	{counter--;handle(counter); printf("%s \n",yytext);}
{others}	{handle(counter); ECHO; printf("\n");}
.
\n
%%


int main()
{

	yylex();
	return(0);
}
