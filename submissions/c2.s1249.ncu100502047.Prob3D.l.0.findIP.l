number	[0-9]
dot	"."
ip	({number}){1,3}({dot}({number}){1,3}){3}
%%
{ip}	{ECHO;}
.	{/*nothing*/}
%%
int main(int argc, char *argv[]){
	yylex();
	return 0;
}
