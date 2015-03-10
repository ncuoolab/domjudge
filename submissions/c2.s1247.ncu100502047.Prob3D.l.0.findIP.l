number	[0-9]
dot	"."
ip	({number}){3}({dot}({number}){3}){3}
%%
{ip}	{ECHO;}
.	{/*nothing*/}
%%
int main(int argc, char *argv[]){
	yylex();
	return 0;
}
