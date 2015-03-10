cpy	cpy
head	[a-zA-Z_$]
seq	[a-zA-Z0-9_$]*
valid	({cpy}{seq}*)|({head}{seq}*{cpy}{seq}*)
legal1	(" "|"("|\t){valid}
legal2	^{valid}
%%
{legal1}	{printf("%s\n",1+yytext);}
{legal2}	{printf("%s\n",yytext);}
.|\n
%%
int main(){
	yylex();
	return(0);
}
