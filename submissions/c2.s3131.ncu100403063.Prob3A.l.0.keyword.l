cpy	cpy
head	[a-zA-Z_$]
seq	[a-zA-Z0-9_$]*
valid	({cpy}{seq}*)|({head}{seq}*{cpy}{seq}*)
legal1	(" "|"("|\t){valid}
%%
{legal1}	{printf("%s",1+yytext);}
.|\n
%%
int main(){
	yylex();
	return(0);
}
