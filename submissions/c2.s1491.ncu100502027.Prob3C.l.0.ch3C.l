hexliteral     [0][xX][0-9A-F]*
%%
{hexliteral}    {ECHO;}
%%
int main(int argc, char *argv[]){
   yylex();
   return(0);
}

