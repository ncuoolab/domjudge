%{
int counter=0,i;
%}
digit	[0-9]
letter	[a-zA-Z]
linehead	"{"
linetail	"}"
%x TAIL
%%
{linehead}	{ECHO;counter++;}
{linetail}	{counter--;ECHO;}
\n	{printf("\n");BEGIN TAIL;}
\t	{/*nothing*/}
.	{ECHO;}
<TAIL>"}"	{counter--;for(i=0;i<counter;i++)printf("\t");ECHO;BEGIN INITIAL;}
<TAIL>"{"	{for(i=0;i<counter;i++)printf("\t");ECHO;counter++;BEGIN INITIAL;}
<TAIL>\t	{/*nothing*/}
<TAIL>.		{for(i=0;i<counter;i++)printf("\t");ECHO;BEGIN INITIAL;}
%%
int main(int argc, char *argv[]){
	yylex();
	return 0;
}
