start	0[x|X]
hex_digit	[0-9A-Fa-f]
legal_input	^{start}({hex_digit}){1,8}$	
%%
{legal_input}	{ECHO;printf("\n");}
.|\n	{;}
%%
int main(int argc, char* args[]){
	yylex();
	return(0);
}

