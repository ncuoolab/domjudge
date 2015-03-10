%x COMMENT
%x COMMENT1
%x COMMENT2
%x COMMENT3
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int count = 0;
int i = 0;
%}
%%
.*\{\n	{printf("%s",yytext);count++;BEGIN COMMENT;}
<COMMENT>.*[\t].*\n	{for(i=0;i<count-1;i++){printf("\t");}printf("%s",yytext);}
<COMMENT>.*\{.*\n     {for(i=0;i<count;i++){printf("\t");}ECHO;count++;}
<COMMENT>.*\}.*\n	{count--;for(i=0;i<count;i++){printf("\t");}ECHO;}
<COMMENT>.*\{.*\}	{ECHO;}
<COMMENT>.*\n	{for(i=0;i<count;i++){printf("\t");} ECHO;}
%%
int main(void){
	yylex();
	return(0);
	
}
