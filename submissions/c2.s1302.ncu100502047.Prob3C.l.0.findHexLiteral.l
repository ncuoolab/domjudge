letter	[a-zA-Z]
digit	[0-9]
targetHead	("0x"|"0X")
target		{targetHead}(({letter}|{digit}){6})
donot		^(([123456789]|{letter})+|("0"{2,}))
%%
{target}	{ECHO; printf("\n");}
{donot}		{/*nothing*/}
\n		{/*nothing*/}
.	{/*nothing*/}
%%
int main(){
	yylex();
	return 0;
}
