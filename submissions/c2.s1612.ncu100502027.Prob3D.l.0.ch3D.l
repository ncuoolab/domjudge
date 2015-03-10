digit [0-255]
adress {digit}"\."{digit}"\."{digit}"\."{digit}
%%
{adress}    {ECHO;printf("\n");}
.|\n            ;
%%
int main(int argc, char *argv[]){
   yylex();
   return(0);
}

