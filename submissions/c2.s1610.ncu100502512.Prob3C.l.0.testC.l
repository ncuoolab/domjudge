

%{
%}
head  0[xX]
range [0-9a-fA-F]
space (\t|" ")
range2 [^\t\n]+
digit {range}{1,8}
digit2 {range}{9}
test1 ^{head}{digit}|{space}{head}{digit}
test2 ^{head}{digit2}
test3 {space}{head}{digit}
%%

{test2}  {}
{test1}  {ECHO; printf("\n");}
{test3}  {printf("%s",yytext+1);}
{range2} {}

. {}
.|\n 
%%

int main(){

yylex();
return(0);
}


