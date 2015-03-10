%{
%}
english [a-fA-F]
digit [0-9]
apple 0X|0x
spac  " "
sta \^
identifier {spac}{apple}({english}|{digit}){1,6}\n
ident ^{apple}({english}|{digit}){1,6}\n
%%
{ident} ECHO;
{identifier} printf("%s",1+yytext);
.|\n ;
%%
int main(){
	yylex();	
	return(0);
}
