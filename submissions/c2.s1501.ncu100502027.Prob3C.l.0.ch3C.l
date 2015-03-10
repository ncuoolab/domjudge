hexliteral    [0][xX][0-9A-Fa-f]*
%%
{hexliteral}    {ECHO;printf("\n");}
.|\n            ;
%%
int main(int argc, char *argv[]){
   yylex();
   return(0);
}

