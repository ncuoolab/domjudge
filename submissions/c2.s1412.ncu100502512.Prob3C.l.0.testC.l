%{
%}
range [0-9]|[a-f]|[A-F]
test  ^['0']['x']{range}+

%%
{test}  {ECHO; printf("\n");}
. {}
.|\n

%%

int main(){

yylex();
return(0);
}


