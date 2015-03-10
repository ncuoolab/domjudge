%{
int counter=0,i;
%}
linehead	"{"
linetail	"}"
%x TAIL
%%
{linehead}	{ECHO;counter++;}
{linetail}	{counter--;ECHO;}
\n	{printf("\n");BEGIN TAIL;}
^" "	{for(i=0;i<counter;i++)printf("\t");}
^(\t)+	{/**/}
.	{ECHO;}
<TAIL>"}"	{counter--;for(i=0;i<counter;i++)printf("\t");ECHO; BEGIN INITIAL;}
<TAIL>"{"	{for(i=0;i<counter;i++)printf("\t");ECHO;counter++; BEGIN INITIAL;}
<TAIL>\t	{/*nothing*/}
<TAIL>" "	{/**/}
<TAIL>\n	{for(i=0;i<counter;i++)printf("\t");printf("\n");}
<TAIL>.		{for(i=0;i<counter;i++)printf("\t");ECHO;BEGIN INITIAL;}
%%
int main(int argc, char *argv[]){
	yylex();
	return 0;
}
