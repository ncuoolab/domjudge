%{
%}
word    [A-Z][A-Za-z]*$
number   ([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])
ip       {number}"."{number}"."{number}"."{number}$
email   	[^ \t\n@]+@(.+"."){1,}.+$
commentword .+
comment    [/]{2}{commentword}$

%%
{comment}  {printf("--"); printf("%s",yytext+2); printf("--\n");}
{word}     {ECHO;printf(" is a word\n");}
{ip}       {ECHO;printf(" is an IP address\n");}
{email}    {ECHO;printf(" is an email address\n");}
.|\n          {}
%%

int main(int argc , char *argv[]){
	yylex();
	return(0);
}
