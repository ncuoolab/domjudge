%x COMMENT 
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
%}
%%
^[^0]   {BEGIN COMMENT;}
<COMMENT>.      {/*do nothing*/}
<COMMENT>\n    {BEGIN INITIAL;}
^0[x|X][0-9]*[a-fA-F]+ {ECHO;}	
%%
int main(void){
	yylex();
	return(0);
}
