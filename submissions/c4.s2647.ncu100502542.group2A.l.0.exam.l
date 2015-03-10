%{
unsigned int tabCount=0,i=0;
%}
tab	^("\t"|" ")*
bracketL	\{
bracketR	\}
nextLine "\n" 
nothing [a-zA-Z0-9].*
leftLine   .*\{.*
rightLine  .*\}.*
%%
{tab}	;
{bracketL}	{for(i=tabCount;i>0;i--)printf("\t");ECHO;tabCount++;}	
{bracketR}	{tabCount--;for(i=tabCount;i>0;i--)printf("\t");printf("%s",yytext);}
{leftLine}	{for(i=tabCount;i>0;i--)printf("\t");ECHO;tabCount++;}
{rightLine}	{tabCount--;for(i=tabCount;i>0;i--)printf("\t");printf("%s",yytext);}
{nextLine}	printf("\n");
{nothing}	for(i=tabCount;i>0;i--)printf("\t");ECHO; 
%%
int main(int argc, char *argv[]) {
	yylex();
	return(0);
}
