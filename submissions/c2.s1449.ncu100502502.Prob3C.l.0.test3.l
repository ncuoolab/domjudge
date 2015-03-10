head	0(X|x)
digit	[0-9]
az	[a-fA-F]
eol	\n
word	[^ 0-9A-F\t\n]
literal	{head}({digit}|{az}){1,8}
nlit	{digit}*{head}({digit}|{az}|{word}){1,8}
%%
{literal}	{ECHO; printf("\n");}
{nlit}	{}
{eol}	{}
%%
int main(){
	yylex();
	return(0);
}