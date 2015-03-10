Eng	[a-zA-z_]
word	{Eng}+
tab	[ |\t]
NCFH	{word}{tab}+{word}{tab}+noodles{tab}+{word}
%%
{NCFH}	{ECHO; printf("\n");}
.|\n	{/*do nothing*/}
%%
int main(int argc, char *argv[]){
	yylex();
	return(0);
}
