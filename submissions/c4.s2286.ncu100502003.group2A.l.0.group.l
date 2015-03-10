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
%x COMMENT
scope1	^[^{}\n]*"{"
scope2	^[^{}\n]*"}"
others	^[^\n]+
space	^[ ]+{others}

%%
[ |\t]			{BEGIN COMMENT;}
<COMMENT>" "   		{}
<COMMENT>"\t"		{}
<COMMENT>{others}	{handle(counter); ECHO; printf("\n"); BEGIN INITIAL;}

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
