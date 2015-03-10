%{
%}
digit [0-9]
alpha [a-fA-F]
head 0x|0X
hex ^{head}({digit}|{alpha}){1,6}\n
%%
{hex} ECHO;
.|\n ;
%%
int main(){
 yylex();
 return 0;
}
