%{
	int numTabs = 0;
	int isFirstOfLine = 1;
%}

line [^\n]
leadSpace ^[ \t]*
leftParam "{"
rightParam "}"

%%

{leadSpace} {}
{leftParam} {
	int i;
	if(isFirstOfLine)for(i=0; i<numTabs; i++)printf("\t");
	printf("%s", yytext);
	numTabs++;
}
{rightParam} {
	int i;
	numTabs--;
	if(isFirstOfLine)for(i=0; i<numTabs; i++)printf("\t");
	printf("%s", yytext);
}
{line} {
	int i;
	if(isFirstOfLine)for(i=0; i<numTabs; i++)printf("\t");
	printf("%s", yytext);
	isFirstOfLine = 0;
}
"\n" {ECHO; isFirstOfLine=1;}

%%

main(){
	yylex();
	return 0;
}