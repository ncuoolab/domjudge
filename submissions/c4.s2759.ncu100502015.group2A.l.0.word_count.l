%{
	int leftcounter=0;int i =0;
%}
%x t
space [ |\t]+
sp [ |\t]*
chr [a-z|A-Z|0-9]
str [^\n\t"{""}"]+
right 	"}"
left	"{"
cor [.|{space}]*
%%
^{left}{cor}\n  {for( i=0;i<leftcounter;i++){printf("\t");};leftcounter++;ECHO;}
\t{left}{cor}\n  {for( i=0;i<leftcounter;i++){printf("\t");};
leftcounter++;printf("%s",yytext+1);}
" "{left}{cor}\n  {for( i=0;i<leftcounter;i++){printf("\t");};
leftcounter++;printf("%s",yytext+1);}
^{right}{cor}\n {leftcounter--;for( i=0;i<leftcounter;i++){printf("\t");};ECHO;}
\t{right}{cor}\n {leftcounter--;for( i=0;i<leftcounter;i++){printf("\t");};
printf("%s",yytext+1);}
" "{right}{cor}\n {leftcounter--;for( i=0;i<leftcounter;i++){printf("\t");};
printf("%s",yytext+1);}
<t>\n {ECHO;BEGIN INITIAL;}
<t>{left} {leftcounter++;ECHO;}
<t>{right} {leftcounter--;ECHO;}
<t>{str} {ECHO;}
^{str} {for( i=0;i<leftcounter;i++){printf("\t");};ECHO;BEGIN t;}
\t{str} {for( i=0;i<leftcounter;i++){printf("\t");};
printf("%s",yytext+1);BEGIN t;}
" "{str} {for( i=0;i<leftcounter;i++){printf("\t");};
printf("%s",yytext+1);BEGIN t;}
. {}

	
%%
int main(int argc, char *argv[]) {
	yylex();	
 	return(0);
}

