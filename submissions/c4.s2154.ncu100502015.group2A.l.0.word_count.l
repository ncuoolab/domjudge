%{
	int leftcounter=0;int i =0;
%}
%x t
right 	"}"
left	"{"
%%
{left}.+\n  {for( i=0;i<leftcounter;i++){printf("\t");};leftcounter++;ECHO;}
{right}.+\n {leftcounter--;for( i=0;i<leftcounter;i++){printf("\t");};ECHO;}
<t>\n {ECHO;BEGIN INITIAL;}
<t>{left} {leftcounter++;ECHO;}
<t>. {ECHO;}
.       {for( i=0;i<leftcounter;i++){printf("\t");};ECHO;BEGIN t;}
	
%%
int main(int argc, char *argv[]) {
	yylex();	
 	return(0);
}

