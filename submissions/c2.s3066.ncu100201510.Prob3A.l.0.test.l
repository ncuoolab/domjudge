%{
/* 會直接照搬放檔頭的C code */
#include <stdio.h>
%}

/* 這裡告訴flex只要讀取輸入的檔案（不需要其他檔案）*/
%option noyywrap


[a-zA-Z_]+[a-zA-Z_0-9]*  id

%%
    /*** 規則區塊***/
id {ECHO;}

.       {   /* 忽略所有其他的字*/   }

%%
/*** C程式碼區塊***/

int main(void)
{
    /* 呼叫lexer，然後結束程式*/
    yylex();
    return 0;
}