digit ([0|1][0-9][0-9])|((25)[0-5])|[2][0-4][0-9]
adress {digit}"\."{digit}"\."{digit}"\."{digit}
%%
{adress}    {ECHO;printf("\n");}
.|\n            ;
%%
int main(int argc, char *argv[]){
   yylex();
   return(0);
}

