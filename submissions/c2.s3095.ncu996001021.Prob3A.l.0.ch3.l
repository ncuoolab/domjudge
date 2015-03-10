%{
#include <stdio.h> 
%}
nid [0-9]+[A-Za-z_$]*cpy[A-Za-z_$0-9]*
id [A-Za-z_$]*cpy[A-Za-z_$0-9]* 
 

%%
{nid}  { }
{id} {printf("%s\n",yytext);}
.    {}
\n   {}
%%

int main(){
    yylex();
    
    return 0;
}
    
