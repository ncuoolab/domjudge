%{
#include <stdio.h>
%}
alphabet 		[a-zA-Z]
digit			[0-9]
iden			({alphabet}|_|$)*({alphabet}|_|$|{digit})*cpy({alphabet}|_|$|{digit})*
		
%%
{iden}			{ECHO;printf("\n");}
.|\n  	        	{/*do nothing*/}
%%
int main(int argc, char *argv[]) {
        yylex();
        return(0);
}

