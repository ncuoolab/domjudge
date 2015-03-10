%{
int counter=0,i;
%}
linehead	"{"
linetail	"}"
%x TAIL
%x BKILL
%%
{linehead}	{ECHO;counter++;}
{linetail}	{counter--;ECHO;}
\n	{printf("\n");BEGIN TAIL;}
\t	{/**/}
.	{ECHO;}
<TAIL>"}"	{counter--;for(i=0;i<counter;i++)printf("\t");ECHO; BEGIN BKILL; BEGIN INITIAL;}
<TAIL>"{"	{for(i=0;i<counter;i++)printf("\t");ECHO;counter++; BEGIN BKILL; BEGIN INITIAL;}
<TAIL>\t	{/*nothing*/}
<TAIL>" "	{/*nothing*/}
<TAIL>\n	{printf("\n");}
<TAIL>.		{for(i=0;i<counter;i++)printf("\t");ECHO;BEGIN INITIAL;}
<BKILL>" "	{BEGIN INITIAL;}
%%
int main(int argc, char *argv[]){
	yylex();
	return 0;
}
