%{
unsigned int count=0;
unsigned int i=0;
%}
%x COMMENT
spa " "
charc [()=;"+\<>*]
digit [0-9]
eng [a-zA-Z]
iden  "{"
iden2 "}"
space [\t]
sentence  ^{spa}*({charc}|{digit}|{spa}|{eng})*
sentence1  {iden}({charc}|{digit}|{spa}|{eng}|{iden})*
sentence2 ^{space}*({charc}|{digit}|{spa}|{eng})*
test  ^{space}*({charc}|{digit}|{spa}|{eng})*{iden}
%%
{space}     {for(i=0;i<count;i++){printf("\t");}}
{iden}      {for(i=0;i<count;i++){ printf("\t");}count++;ECHO;}
{test}      {for(i=0;i<count;i++){ printf("\t");}count++;ECHO;}
{sentence}   {for(i=0;i<count;i++){ printf("\t");};ECHO;}
{iden2} {count--;for(i=0;i<count;i++){ printf("\t");};ECHO;}
%%
int main(){
        yylex();
        return(0);
}
