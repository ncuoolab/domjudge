
%{
%}
head  0[xX]
range [0-9a-fA-F]
range2 [^\t\n]+
digit {range}{1,8}
digit2 {range}{9}
test1 ^{head}{digit}
test2 ^{head}{digit2}

%%
{test1}  {ECHO; printf("\n");}
{test2}  {}
{range2} {}
. {}
.|\n 
%%

int main(){

yylex();
return(0);
}


