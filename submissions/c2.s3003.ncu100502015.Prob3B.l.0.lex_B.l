letter 	[a-zA-Z]+
space	[ ]+
judge 	{letter}{space}{letter}{space}"noodles"{space}{letter}
%%
{judge}	{ECHO;printf("\n");}
.|\n	;
%%
int main(){
	yylex();
	return(0);
}
