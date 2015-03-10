%{
#include <stdio.h> 
%}
id [A-Za-z_$]*cpy[A-Za-z_$0-9]* 
 

%%
{id} {printf("%s\n",yytext);}
.    {}
\n   {}
%%

int main(){
    yylex();
    
    return 0;
}
    

