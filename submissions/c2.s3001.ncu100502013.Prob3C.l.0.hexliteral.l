%{
int count=0;
%}

digit	[0-9A-Fa-f_]{1,8}$
head	(0x|0X)
space	[ ]
%%
{space}				{count++;}
^{space}*{head}{digit}		{fprintf(yyout, "%s\n", yytext+count);count=0;}
.|\n				{}
%%
int main(void){
	yylex();
	return(0);
}
