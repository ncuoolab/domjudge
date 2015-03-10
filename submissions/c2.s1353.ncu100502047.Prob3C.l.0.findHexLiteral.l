letter	[a-fA-F]
digit	[0-9]
targetHead	("0x"|"0X")
target		{targetHead}(({letter}|{digit}){6})
donot		^(([123456789]|{letter})+|("0"{2,}))
%x SKIP
%%
{target}	{ECHO; printf("\n"); BEGIN SKIP;}
{donot}		{/*nothing*/}
\n		{/*nothing*/}
<SKIP>.		{/*nothing*/}
<SKIP>\n	{BEGIN INITIAL;}
.	{/*nothing*/}
%%
int main(int argc, char *argv[]){
	yylex();
	return 0;
}
