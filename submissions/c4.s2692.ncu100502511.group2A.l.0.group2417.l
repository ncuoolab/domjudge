%{
unsigned int count=0;
unsigned int i=0;
%}
%x COMMENT
spa " "
charc [()=.;"+\!<>/*]
digit [0-9]
eng [a-zA-Z]
iden  "{"
iden2  "}"
space [\t]
sentence  ^{spa}*({charc}|{digit}|{spa}|{eng})*
sentence1  {iden}({charc}|{digit}|{spa}|{eng}|{iden})*
sentence2 ^{space}*({charc}|{digit}|{spa}|{eng})*
test  ^{space}*({charc}|{digit}|{spa}|{eng})*{iden}
test2 ^{space}*({charc}|{digit}|{spa}|{eng})+{iden2}$
part  ^{spa}*({charc}|{digit}|{spa}|{eng})+{iden}{spa}*({charc}|{digit}|{spa}|{eng})*{iden2}$
%%
{part}      {for(i=0;i<count;i++){printf("\t");}ECHO;}
{space}     {;}
{test}      {for(i=0;i<count;i++){ printf("\t");}count++;ECHO;}
{sentence}  {for(i=0;i<count;i++){ printf("\t");};ECHO;}
{test2}     {ECHO;}
{iden}      {for(i=0;i<count;i++){ printf("\t");}count++;ECHO;}
{iden2}   {count--;for(i=0;i<count;i++){ printf("\t");};ECHO;}

%%
int main(){
        yylex();
        return(0);
}
