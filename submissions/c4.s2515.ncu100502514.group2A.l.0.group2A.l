%{
	int numTabs = 0; //making by "{", "}"
	int isFirstOfLine = 1;
	int i;
%}

line [^\n]
leadSpace ^[ \t]*
leftParam "{"
rightParam "}"

%x SINGLE_COMMENT
%x BLOCK_COMMENT
%x SINGLE_QUOTE
%x DOUBLE_QUOTE

%%

"\"" {if(isFirstOfLine)for(i=0; i<numTabs; i++)printf("\t"); ECHO; isFirstOfLine = 0; BEGIN DOUBLE_QUOTE;}
"\'" {if(isFirstOfLine)for(i=0; i<numTabs; i++)printf("\t"); ECHO; isFirstOfLine = 0; BEGIN SINGLE_QUOTE;}
"//" {if(isFirstOfLine)for(i=0; i<numTabs; i++)printf("\t"); ECHO; isFirstOfLine = 0; BEGIN SINGLE_COMMENT;}
"/*" {if(isFirstOfLine)for(i=0; i<numTabs; i++)printf("\t"); ECHO; isFirstOfLine = 0; BEGIN BLOCK_COMMENT;}

<DOUBLE_QUOTE>"\"" {if(isFirstOfLine)for(i=0; i<numTabs; i++)printf("\t"); ECHO; isFirstOfLine = 0; BEGIN INITIAL;}
<SINGLE_QUOTE>"\'" {if(isFirstOfLine)for(i=0; i<numTabs; i++)printf("\t"); ECHO; isFirstOfLine = 0; BEGIN INITIAL;}
<SINGLE_COMMENT>\n|\r {ECHO; BEGIN INITIAL; isFirstOfLine=1;}
<BLOCK_COMMENT>"*/" {if(isFirstOfLine)for(i=0; i<numTabs; i++)printf("\t"); ECHO; isFirstOfLine = 0; BEGIN INITIAL;}

<DOUBLE_QUOTE>{leadSpace} {}
<DOUBLE_QUOTE>. {
	if(isFirstOfLine)for(i=0; i<numTabs; i++)printf("\t");
	printf("%s", yytext);
	isFirstOfLine = 0;
}
<DOUBLE_QUOTE>\n|\r {ECHO; isFirstOfLine=1;}
<DOUBLE_QUOTE>\\\\ {
	if(isFirstOfLine)for(i=0; i<numTabs; i++)printf("\t");
	printf("%s", yytext);
	isFirstOfLine = 0;
}
<DOUBLE_QUOTE>\\\" {
	if(isFirstOfLine)for(i=0; i<numTabs; i++)printf("\t");
	printf("%s", yytext);
	isFirstOfLine = 0;
}
<SINGLE_QUOTE>{leadSpace} {}
<SINGLE_QUOTE>. {
	if(isFirstOfLine)for(i=0; i<numTabs; i++)printf("\t");
	printf("%s", yytext);
	isFirstOfLine = 0;
}
<SINGLE_QUOTE>\n|\r {ECHO; isFirstOfLine=1;}
<SINGLE_QUOTE>\\\\ {
	if(isFirstOfLine)for(i=0; i<numTabs; i++)printf("\t");
	printf("%s", yytext);
	isFirstOfLine = 0;
}
<SINGLE_QUOTE>\\\' {
	if(isFirstOfLine)for(i=0; i<numTabs; i++)printf("\t");
	printf("%s", yytext);
	isFirstOfLine = 0;
}
<SINGLE_COMMENT>{leadSpace} {}
<SINGLE_COMMENT>. {ECHO;}
<BLOCK_COMMENT>{leadSpace} {}
<BLOCK_COMMENT>. {
	if(isFirstOfLine)for(i=0; i<numTabs; i++)printf("\t");
	printf("%s", yytext);
	isFirstOfLine = 0;
}
<BLOCK_COMMENT>\n|\r {ECHO; isFirstOfLine=1;}

{leadSpace} {}
{leftParam} {
	if(isFirstOfLine)for(i=0; i<numTabs; i++)printf("\t");
	isFirstOfLine = 0;
	printf("%s", yytext);
	numTabs++;
}
{rightParam} {
	if(numTabs>0)numTabs--;
	if(isFirstOfLine)for(i=0; i<numTabs; i++)printf("\t");
	isFirstOfLine = 0;
	printf("%s", yytext);
}
{line} {
	if(isFirstOfLine)for(i=0; i<numTabs; i++)printf("\t");
	printf("%s", yytext);
	isFirstOfLine = 0;
}
\n|\r {ECHO; isFirstOfLine=1;}

%%

main(){
	yylex();
	printf("\nwrong\n");
	return 0;
}