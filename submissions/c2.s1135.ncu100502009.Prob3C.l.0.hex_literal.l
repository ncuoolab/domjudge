
hex_digit	[0-9A-Fa-f_]{1,8}
identifier  	^(0x|0X){hex_digit}+
%%
{identifier}	{ECHO; printf("\n");}
.|\n		{/*do nothing*/}
%%
int main(int argc,char* argv[]){
	yylex();
	return(0);
}
