letter  [a-fA-F]
digit [0-9]
hex1 ^(0x|0X)({letter}|{digit}){1,8}$
hex2 " "(0x|0X)({letter}|{digit}){1,8}$
%%
{hex1}    {ECHO;printf("\n");}
{hex2}    {ECHO;printf("\n");}
.|\n            ;
%%
int main(int argc, char *argv[]){
   yylex();
   return(0);
}

