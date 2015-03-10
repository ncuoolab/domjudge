number [0-9]
letter [a-fA-F]
hex {number}|{letter}
literal (0x|0X){hex}{hex}{hex}{hex}{hex}{hex}
%%
{literal} {printf("%s\n",yytext);}
.|\n ;
%%
int main(){
	yylex();
	return(0);
}
