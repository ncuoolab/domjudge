number [0-9]
letter [a-fA-F]
hex {number}|{letter}
literal (^|[ ])(0x|0X){hex}{1,6}\n
%%
{literal} {printf("%s",yytext);}
.|\n ;
%%
int main(){
	yylex();
	return(0);
}
