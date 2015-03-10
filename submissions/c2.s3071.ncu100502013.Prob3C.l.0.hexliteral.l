%x	SPAACE
digit	[0-9A-Fa-f_]{1,8}$
head	(0x|0X)
space	^([ ])*
%%
{space}				{BEGIN SPAACE;}
<SPAACE>{head}{digit}		{ECHO;printf("\n");BEGIN INITIAL;}
.|\n				{}
%%
int main(void){
	yylex();
	return(0);
}
