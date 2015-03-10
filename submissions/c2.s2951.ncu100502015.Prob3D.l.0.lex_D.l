%x COMMENT
byte9	[1-9]
byte99	[1-9][0-9]
byte199 [1][0-9][0-9]
byte249 [2][0-4][0-9]
byte255 [2][5][0-5]
byte    {byte199}|{byte249}|{byte255}|{byte99}|{byte9}
ip	{byte}{point}{byte}{point}{byte}{point}{byte}[ ]
point   "."
%%
{ip}		{ECHO;BEGIN COMMENT;}
<COMMENT>. 	{}
<COMMENT>\n 	{BEGIN INITIAL; printf("\n");}
.|\n    	{}
%%
int main(int argc,char *argv[]){
	yylex();
	return(0);
}
