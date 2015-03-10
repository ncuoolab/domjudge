%{
int count=0;
%}
%x into	
lbracket 	"{"
rbracket	"}"
other		"/"
all		.
space		[ ]
word		[^\n\t"{""}"]
tab		"\t"
%%
"{"		{ECHO;count++;BEGIN(into);}
<into>^\r 	{int i=0;for(i;i<count;i++){printf("\t");}}
<into>^"\t"*" "*	{int i=0;for(i;i<count;i++){printf("\t");}}
<into>^" "*	{int i=0;for(i;i<count;i++){printf("\t");}}
<into>^({word}|"/")	{int i=0;for(i;i<count;i++){printf("\t");}ECHO;}
<into>^"\t"+"}"	{int i=0;for(i;i<count-1;i++){printf("\t");}printf("}");count--;}
<into>^"\t"*	{int i=0;for(i;i<count;i++){printf("\t");}}
<into>^"{"	{int i=0;for(i;i<count;i++){printf("\t");}ECHO;count++;BEGIN(into);}
<into>"{"	{ECHO;count++;BEGIN(into);}
<into>^"}"	{int i=0;for(i;i<count-1;i++){printf("\t");}ECHO;count--;}
<into>"}"	{int i=0;for(i;i>count-1;i++){printf("\t");}ECHO;count--;}
<into>.		{ECHO;}	
<into>\n	{ECHO;}
.		{ECHO;}
\n		{ECHO;}
%%
int main(char *argc)
{
	yylex();
	return 0;
}
