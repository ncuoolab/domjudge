identifier    [a-zA-Z]*[^( \n\t]*"cpy"[^ (\n\t]*
%%
{identifier}     {if(!(yytext[0]>='0'&&yytext[0]<='9')){
			ECHO;
			printf("\n");}
		 }
.|\n             ;
%%
int main(int argc, char *argv){
	yylex();
	return(0);
}
