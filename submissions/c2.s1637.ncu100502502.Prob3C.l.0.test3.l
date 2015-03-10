head	0(X|x)
digit	[0-9]
az	[a-fA-F]
eol	\n
word	[^ 0-9A-F\n]
other	'('{digit}+')'
literal	{head}({digit}|{az}|{other}){1,8}$
nlit	({word}|{az}|[1-9])+{head}({digit}|{az}|{other}){1,8}$
%%
{nlit}	{}
{literal}	{ECHO; printf("\n");}
{eol}	{}
.	{}
%%
int main(void){
	yylex();
	return(0);
}
