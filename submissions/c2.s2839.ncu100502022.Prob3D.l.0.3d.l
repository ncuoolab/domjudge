a	[0-9]|[1-9][0-9]|[1][0-9][0-9]|[2][0-4][0-9]|[2][5][0-5] 
ip	{a}"."{a}"."{a}"."{a}[ ] 
%% 
{ip}	{ECHO;printf("\n");} 
.|\n	; 
%% 
int main(int argc, char *argv[]){
		yylex();
		return 0;
}
