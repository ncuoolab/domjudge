%{
#include <stdio.h> 
%}

id [0-9]+\.[0-9]+\.[0-9]+ 
 

%%

{id} {printf("%s\n",yytext);}
.    {}
\n   {}
%%

int main(){
    yylex();
    
    return 0;
}
    
