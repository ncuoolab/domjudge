%{
char token[100];
%}
word	[^ \t\n()]
id	{word}+
%%
{id}	{if(!isdigit(yytext[0])){
		if(strstr(yytext,"cpy")){
			ECHO;
			printf("\n");
		}
	 }
	}
.|\n	{/*nothing*/}
%%
int main(int argc, char *argv[]){
	yylex();
	return 0;
}
