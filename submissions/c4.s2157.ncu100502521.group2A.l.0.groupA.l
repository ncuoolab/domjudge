%{
 int tabcount = 0;int i = 0;
%}
word . 
line ^{word}*$
lineadd ^{word}*"{"$
linedec ^{word}*"}"$
%%
{lineadd} {for(i=0;i<tabcount;i++){printf("\t");}ECHO;tabcount++;}
{linedec} {tabcount--;for(i=0;i<tabcount;i++){printf("\t");}ECHO;}
{line} {for(i = 0; i < tabcount;i++){printf("\t");}ECHO;}
. {}
%%
int main() {
	yylex();
	return 0;
}
