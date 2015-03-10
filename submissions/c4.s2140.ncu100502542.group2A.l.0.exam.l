%{
unsigned int tabCount=0,i=0;
%}
tab	("\t"|" ")
bracketL	^\{.*$
bracketR	^\}.*$
nextLine "\n" 
nothing .* 
%% 
{tab}	;
{bracketL}	{tabCount++;ECHO;}
{bracketR}	tabCount--;ECHO;
{nothing}	 for(i=tabCount;i>0;i--)printf("\t");ECHO; 
%%
int main(int argc, char *argv[]) {
	yylex();
	return(0);
}
