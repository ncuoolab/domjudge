number	[0-9]
dot	"."
blank	" "
ip	({number}){1,3}({dot}({number}){1,3}){3}
%x SKIP
%%
{ip}	{ECHO;}
{blank}	{BEGIN SKIP;}
<SKIP>.	{/*nothing*/}
<SKIP>\n	{printf("\n");BEGIN INITIAL;}
.	{/*nothing*/}
%%
int main(int argc, char *argv[]){
	yylex();
	return 0;
}
