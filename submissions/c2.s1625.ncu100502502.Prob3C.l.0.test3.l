head	0(X|x)
digit	[0-9]
az	[a-fA-F]
eol	\n
word	[^ 0-9A-F\n]
other	'('{digit}+')'
literal	{head}({digit}|{az}|{other}){1,8}$
nlit	({word}|{az})+{head}({digit}|{az}|{other}){1,8}$
%%
{nlit}	{}
{literal}	{ECHO; printf("\n");}
{word}	{}
{eol}	{}
.	{}
%%
int main(void){
	yylex();
	return(0);
}
