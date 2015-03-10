letter [a-fA-F]
digit [0-9]
test 0X|0x
identifier ^{test}({letter}|{digit}){1,6}\n
%%
{identifier} ECHO;
.|\n ;
%%
int main(){
	yylex();	
	return(0);
}
