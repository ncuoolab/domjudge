
%{
%}
range [0-9]|[a-f]|[A-F]
digit {range}{1,8}
test ^0['x''X']{digit}

%%
{test}  {ECHO; printf("\n");}
. {}
.|\n

%%

int main(){

yylex();
return(0);
}


