number	[0-9]
dot	"."
blank	" "
ip	({number}){1,3}({dot}({number}){1,3}){3}
%%
{ip}	{ECHO;}
{blank}	{exit(0);}
.	{/*nothing*/}
%%
int main(int argc, char *argv[]){
	yylex();
	return 0;
}
