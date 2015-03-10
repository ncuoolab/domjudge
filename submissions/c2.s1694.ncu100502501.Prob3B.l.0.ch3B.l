%{
#include <stdio.h>
%}
Name	 [a-zA-Z]+
Career	[a-zA-Z]+
Favorite	[a-zA-Z]+
Hometown	[a-zA-Z]+
Space	[ \t]+
noo     [n][o][o][d][l][e][s]
print   {Name}{Space}{Career}{Space}{noo}{Space}{Hometown}
%%
{print}	{ECHO;}
.       {/**/} 
%%

int main(int argc, char *argv[]) {
	yylex();
 	return(0);
}
