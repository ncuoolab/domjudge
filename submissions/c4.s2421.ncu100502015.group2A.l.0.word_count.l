%{
	int leftcounter=0;int i =0;
%}
%x t
space [ |\t]+
chr [a-z|A-Z|0-9]
str [^\n\t"{""}"]+
right 	"}"
left	"{"
%%
{left}.*\n  {for( i=0;i<leftcounter;i++){printf("\t");};leftcounter++;ECHO;}
{right}.*\n {leftcounter--;for( i=0;i<leftcounter;i++){printf("\t");};ECHO;}
<t>\n {ECHO;BEGIN INITIAL;}
<t>{left} {leftcounter++;ECHO;}
<t>{right} {leftcounter--;ECHO;}
<t>{str} {ECHO;}
^{str} {for( i=0;i<leftcounter;i++){printf("\t");};ECHO;BEGIN t;}
\t{str} {for( i=0;i<leftcounter;i++){printf("\t");};
printf("%s",yytext+1);BEGIN t;}
\t\t{str} {for( i=0;i<leftcounter;i++){printf("\t");};
printf("%s",yytext+2);BEGIN t;}
\t\t\t{str} {for( i=0;i<leftcounter;i++){printf("\t");};
printf("%s",yytext+2);BEGIN t;}


	
%%
int main(int argc, char *argv[]) {
	yylex();	
 	return(0);
}

