head	0(X|x)
digit	[0-9]
az	[a-fA-F]
eol	\n
word	[^/0-9A-F\n]
literal	{head}({digit}|{az}){1,6}
nlit	({digit}|{word})*({head}|X|x)({digit}|{az}|{word}){1,6}
%x COMMENT
%%
"//"	{BEGIN COMMENT;}
<COMMENT>.[^\n]	{/*do nothing*/}
<COMMENT>\n	{BEGIN INITIAL;}
{literal}	{ECHO; printf("\n");}
{nlit}	{}
{eol}	{}
.	{}
%%
int main(void){
	yylex();
	return(0);
}
