%{
#include <stdio.h> 
%}

id [0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}
 

%%
{id} {printf("%s\n",yytext);}
.    {}
\n   {}
%%

int main(){
    yylex();
    
    return 0;
}
    
