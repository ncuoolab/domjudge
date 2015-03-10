%x COMMENT
letter  [a-fA-F]
digit [0-9]
hex ^[ ]*(0x|0X)({letter}|{digit}){1,8}$
%%
{hex1}    {ECHO;printf("\n");}
.|\n            ;
{note} {BEGIN COMMENT;}
<COMMENT>{hex2} {ECHO;printf("\n");BEGIN INITIAL;}
%%
int main(int argc, char *argv[]){
   yylex();
   return(0);
}

