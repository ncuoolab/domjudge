IPInteger	(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9][0-9]|[0-9])
IPAddress	{IPInteger}\.{IPInteger}\.{IPInteger}\.{IPInteger}
%%
{IPAddress}	{ECHO;printf("\n");}
.|\n		{}
%%
int main(void){
	yylex();
	return(0);
}
