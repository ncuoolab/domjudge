space    " "
dot	 "."
title	 "//"[a-zA-Z]*{space}*[a-zA-Z]*
first	 [A-Z]
word 	 {first}[a-zA-z]*
num	 ([0-9])|([1-9][0-9])|([1][0-9][0-9])|([2][0-4][0-9])|([2][5][0-5])
token	 [a-zA-Z0-9]+
end	 {dot}{token}
Em	^[^ \t\n]+"@"{token}{end}+$
IP	^{num}{dot}{num}{dot}{num}{dot}{num}$

%%
{title}	 {fprintf(yyout,"--%s--",yytext+2);printf("\n");}
{word}	 {fprintf(yyout,"%s is a word",yytext); printf("\n");}
{Em}     {fprintf(yyout,"%s is an email address",yytext);printf("\n");}
{IP}     {fprintf(yyout,"%s is an IP address",yytext); printf("\n");}

.|\n	 {}
%%
int main(void){
	yylex();
	return(0);
}
