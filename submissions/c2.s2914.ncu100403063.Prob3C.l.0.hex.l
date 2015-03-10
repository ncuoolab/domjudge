%x COMMENT
%x COMMENT1
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
%}
%%
^[^0]  {BEGIN COMMENT;}
^.[g-zG-Z]+     {BEGIN COMMENT1;}
^.{1}[^(x|X)]   {BEGIN COMMENT;}
<COMMENT>.     {/*do nothing*/}
<COMMENT>\n    {BEGIN INITIAL;}
<COMMENT1>.     {/*do nothing*/}
<COMMENT1>\n    {BEGIN INITIAL;}
^0(x|X)+[0-9]*[a-fA-F]+ {ECHO;}
%%
int main(void){
        yylex();
        return(0);
}
