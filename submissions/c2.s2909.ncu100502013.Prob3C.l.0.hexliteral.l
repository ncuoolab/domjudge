digit	[0-9A-Fa-f_]+
head	^(0x|0X)
%%
{head}{digit}	{ECHO;printf("\n");}
.|\n		{}
%%
int main(void){
	yylex();
	return(0);
}
