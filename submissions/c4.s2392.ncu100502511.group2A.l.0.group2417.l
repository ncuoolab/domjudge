%{
unsigned int count=0;
unsigned int i=0;
%}
%x COMMENT
spa " "
charc [()=;"+\<>*]
digit [0-9]
eng [a-zA-Z]
iden "{"
iden2 "}"
space [\t]
sentence  ^[/t]*({charc}|{digit}|{spa}|{eng})*
sentence1  {iden}({charc}|{digit}|{spa}|{eng}|{iden})*
sentence2 ^{space}*({charc}|{digit}|{spa}|{eng})*
%%
"//" {BEGIN COMMENT;ECHO;}
<COMMENT>.$ {ECHO;BEGIN INITIAL;}
{space}   {for(i=0;i<count;i++){printf("\t");}}
{iden} {for(i=0;i<count;i++){ printf("\t");};count++;ECHO;}
{sentence} {for(i=0;i<count;i++){ printf("\t");};ECHO;}
{iden2} {count--;for(i=0;i<count;i++){ printf("\t");};ECHO;}
%%
int main(){
        yylex();
        return(0);
}
