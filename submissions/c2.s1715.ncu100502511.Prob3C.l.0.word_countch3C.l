%{
%}
english [a-fA-F]
digit [0-9]
apple 0X|0x
spac  " "
identifier ^{spac}{0,1}{apple}({english}|{digit}){1,6}\n
identifier2 ^{apple}({english}|{digit}){1,6}\n
%%
{identifier2} ECHO;
{identifier} printf("%s",1+yytext);printf("\n");
.|\n ;
%%
int main(){
	yylex();	
	return(0);
}
