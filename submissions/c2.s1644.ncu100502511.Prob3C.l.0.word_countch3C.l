letter [a-gA-G]
digit [0-9]

test 0X|0x
identifier ^{test}({letter}|{digit}){1,6}\n
%%
{identifier} ECHO;
.|\n ;
%%
int main(int argc, char *argv[]){
	yylex();	
	return(0);
}
