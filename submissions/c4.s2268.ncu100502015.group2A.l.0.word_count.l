%{
	int leftcounter=0;int i =0;
%}
%x t
space [ |\t]*
chr [a-z|A-Z|0-9]
str [^\n\t"{"]+
right 	"}"
left	"{"
%%
{space}{left}.*\n  {for( i=0;i<leftcounter;i++){printf("\t");};leftcounter++;ECHO;}
{space}{right}.*\n {leftcounter--;for( i=0;i<leftcounter;i++){printf("\t");};ECHO;}
<t>\n {ECHO;BEGIN INITIAL;}
<t>{left} {leftcounter++;ECHO;}
<t>{str} {ECHO;}
{space}str {for( i=0;i<leftcounter;i++){printf("\t");};ECHO;BEGIN t;}
	
%%
int main(int argc, char *argv[]) {
	yylex();	
 	return(0);
}

