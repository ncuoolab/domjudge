identifier    [a-zA-Z_"$"]+"cpy"[a-zA-Z0-9_$]*
id            "cpy"[a-zA-Z0-9_$]*
%%
{identifier}     {if(!(yytext[0]>='0'&&yytext[0]<='9')){
			printf("%s",yytext);
			printf("\n");}
		 }
{id}             {ECHO;printf("\n");}
.|\n             ;
%%
int main(int argc, char *argv){
	yylex();
	return(0);
}
